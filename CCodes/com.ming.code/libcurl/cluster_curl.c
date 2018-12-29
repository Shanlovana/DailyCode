//
// Created by ubuntu on 18-12-26.
//

/*
    * curl的封装的具体实现，有以下操作：
    * 1.发送信息：get、post、put、delete
    * 2.上传文件处理
    * 3.下载文件
*/

#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include "cluster_curl.h"
#include <curl/curl.h>

static bool s_global_init_status = 0;        //判断是否已进行全局初始化，0表示未初始化，1表示已经初始化


/*
    * 回调函数，处理返回的数据
    * 参数1：缓存存放
    * 参数2：缓存块数
    * 参数3：缓存每块大小
    * 参数4：WRITEDATA对应的数据流
    * 返回值，数据所占字节数
*/
static size_t http_data_writer(void* buffer, size_t size, size_t nmemb, void* content)
{
    long totalSize = size*nmemb;
    st_curl_rec* p_rec = (st_curl_rec*)content;

    if((NULL != buffer) && (totalSize < (sizeof(p_rec->rec) - p_rec->len)))
    {
        memcpy((char*)(p_rec->rec + p_rec->len), (char*)buffer, totalSize);
        p_rec->len = p_rec->len + totalSize;
        return totalSize;
    }
    else
    {
        EPRINT("http_data_writer data error(%d) \n", errno);
        return 0;
    }

}


/*
    * 回调函数，上传文件处理，读文件
    * 参数1：缓存存放
    * 参数2：缓存块数
    * 参数3：缓存每块大小
    * 参数4：READDATA对应的数据流
    * 返回值，数据所占字节数
*/
static size_t http_read_file(void* buffer, size_t size, size_t nmemb, void* file)
{
    return fread(buffer, size, nmemb, (FILE *)file);
}


/*
    * 回调函数，下载文件处理，写文件
    * 参数1：缓存存放
    * 参数2：缓存块数
    * 参数3：缓存每块大小
    * 参数4：WRITEDATA对应的数据流
    * 返回值，数据所占字节数
*/
static size_t http_write_file(void* buffer, size_t size, size_t nmemb, void* file)
{
    return fwrite(buffer, size, nmemb, (FILE *)file);
}


/*
    * 进行单个线程CURL简单资源进行初始化
    * 返回值：curl资源的指针
*/
CURL* curl_init_resource()
{
    return curl_easy_init();
}


/*
    * 进行单个线程CURL简单资源进行释放
    * 参数1：curl指针，通过此指针进行相关资源释放
    * 返回值为int, 0表示成功，其他表示失败
*/
int curl_release_resource(CURL* curl)
{
    if(NULL == curl)
    {
        EPRINT("rurl_release_resource curl ptr is null \n");
        return -1;       //CURL指针为NULL
    }
    curl_easy_cleanup(curl);
    curl = NULL;

    return 0;
}


/*
    * 宏定义数据格式字符串
*/
//XML格式
#define  XML_FORMAT_STRING        "Content-Type: application/xml;charset=UTF-8"
//JSON格式
#define  JSON_FORMAT_STRING       "Content-Type: application/json;charset=UTF-8"

//临时数组大小
#define  TEMP_FORMAT_MAX_SIZE     (128)

/*
    * 设置消息头
    * 参数1：数据格式,0默认，1为xml,2为json
    * 返回值int, 0表示成功, 其它表示失败
*/
static int curl_set_headers(CURL* curl, const int format,  struct curl_slist** headers)
{
    if(NULL == curl || NULL == headers)
    {
        EPRINT("curl_set_headers curl or headers ptr is null \n");
        return -1;       //CURL_PARAMS指针为NULL
    }

    char temp[TEMP_FORMAT_MAX_SIZE] = {0};
    if(FORMAT_XML == format)
    {
        strncpy(temp, (char*)XML_FORMAT_STRING, sizeof(temp)-1);
    }
    else if(FORMAT_JSON == format)
    {
        strncpy(temp, (char*)JSON_FORMAT_STRING, sizeof(temp)-1);
    }

    if(NULL != temp && '\0' != temp[0])
    {
        *headers = curl_slist_append(NULL, (char*)temp);
        if(NULL == headers)
        {
            EPRINT("curl_set_headers format error(%d) \n", errno);
            return -1;
        }
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, *headers);
        return 0;
    }

    return -1;
}


/*
    * 设置传输的用户和密码验证
    * 参数1：curl指针，通过此指针进行设置用户密码操作
    * 参数2：curl参数结构体
    * 返回值int, 0表示成功，其他表示失败
*/
static int set_user_pwd(CURL* curl, const st_curl_params* curl_params)
{
    if(NULL == curl || NULL == curl_params)
    {
        EPRINT("set_user_pwd curl or curl_params ptr is null \n");
        return -1;       //CURL指针为NULL
    }

    if(curl_params->user[0] && curl_params->pwd[0])
    {
        char temp[MAX_TEMP_LEN] = {0};
        snprintf(temp, sizeof(temp)-1, "%s:%s", curl_params->user, curl_params->pwd);
        curl_easy_setopt(curl, CURLOPT_USERPWD, temp);
    }
    return 0;
}


/*
    * CURL公共操作
    * 参数1：curl指针，通过此指针进行相关设置
    * 参数2：curl数据传送格式,0默认,1为xml,2为json
    * 参数3：curl参数结构体
    * 返回值int，0表示成功，其他表示失败
*/
static int message_public_method(CURL* curl, st_curl_params* curl_params)
{


    if(NULL == curl || NULL == curl_params)
    {
        EPRINT("message_public_method curl or curl_params ptr is null \n");
        return -1;       //CURL指针为NULL
    }

    //指定url
    if(!(curl_params->ip[0]))
    {
        EPRINT("message_public_method ip ptr is null \n");
        return -1;
    }
    char url[MAX_URL_LEN] = {0};
    snprintf(url, sizeof(url)-1, "http://%s%s", curl_params->ip, curl_params->url_path);
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_PORT, curl_params->port);

    //设置用户名和密码
    int nCode = -1;
    nCode = set_user_pwd(curl, curl_params);
    if(0 != nCode)
    {
        EPRINT("message_public_method call set_user_pwd error(%d) \n", errno);
        return -1;
    }

    //禁用掉alarm这种超时
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);

    //设置超时时间
    if(0 >= curl_params->connect_timeout)
    {
        curl_params->connect_timeout = C_CONNECT_DEFAULT_TIMEOUT;
    }
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, curl_params->connect_timeout);

    if(0 >= curl_params->timeout)
    {
        curl_params->timeout = C_DEFAULT_TIMEOUT;
    }
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, curl_params->timeout);

    /*
    默认情况下libcurl完成一个任务以后，出于重用连接的考虑不会马上关闭,如果每次目标主机不一样，这里禁止重连接
    每次执行完curl_easy_perform，licurl会继续保持与服务器的连接。接下来的请求可以使用这个连接而不必创建新的连接,如果目标主机是同一个的话。
    */
    curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1);

    return 0;

}


/*
	* curl返回值处理
	* 参数1: curl返回码
	* 返回值int, 0表示成功, 其他表示失败
*/
static int dealResCode(CURL* curl, const CURLcode res)
{
    //输出返回码代表的意思
    int nCode = 0;
    const char* pRes = NULL;
    pRes = curl_easy_strerror(res);
    DPRINT("%s\n",pRes);

    //http返回码
    long lResCode = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &lResCode);

    if(CURLE_OK != res || 200 != lResCode)
    {
        //curl传送失败
        if(CURLE_OPERATION_TIMEOUTED == res)
        {
            nCode = 1;   //超时返回1
        }
        else
        {
            nCode = -1;    //其它错误返回-1
        }
        EPRINT("curl send msg error: pRes=%s, lResCode=%ld \n", pRes, lResCode);
    }

    return nCode;
}



/*
    * 通过put的方式操作
    * 参数1: curl指针
    * 参数1：curl参数结构体
    * 参数2：要发送的数据
    * 参数3：返回的数据结构体
    * 返回值int, 0表示成功, 1表示超时,其他表示失败
*/
static int put_msg(CURL* curl,
                   st_curl_params* curl_params,
                   const char* msg,
                   st_curl_rec* curl_rec)
{
    CURLcode res = CURLE_OK;
    int nCode = -1;

    if(NULL == curl || NULL == curl_params || NULL == curl_rec)
    {
        EPRINT("put_msg curl or curl_params or curl_rec is null \n");
        return -1;       //CURL_PARAMS指针为NULL
    }

    //发送数据,以及发送方式
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
    if(NULL != msg && '\0' != msg[0])
    {
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, msg);
    }
    else
    {
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
    }


    //设置消息头
    struct curl_slist *headers = NULL;
    if(FORMAT_XML == curl_params->format || FORMAT_JSON == curl_params->format)
    {
        curl_set_headers(curl, curl_params->format, &headers);
    }

    //CURL公共操作方式
    nCode = message_public_method(curl, curl_params);
    if(0 != nCode)
    {
        //释放头结构体
        if(NULL != headers)
        {
            curl_slist_free_all(headers);
            headers = NULL;
        }

        EPRINT("put_msg call message_public_method failure \n");
        return -1;
    }

    // 设置回调函数
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, http_data_writer);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)curl_rec);
    res = curl_easy_perform(curl);

    //释放头结构体
    if(NULL != headers)
    {
        curl_slist_free_all(headers);
        headers = NULL;
    }

    //处理curl返回值
    nCode = dealResCode(curl, res);
    if(0 > nCode)
    {
        EPRINT("deal response code error \n");
    }

    //返回标识码
    return nCode;

}


/*
    * 通过delete的方式操作
    * 参数1: curl指针
    * 参数2: curl参数结构体
    * 参数3: 要发送的数据,此方式可空
    * 参数4: 返回的数据结构体
    * 返回值int, 0表示成功, 1表示超时,其他表示失败
*/
static int delete_msg(CURL* curl,
                      st_curl_params* curl_params,
                      const char* msg,
                      st_curl_rec* curl_rec)
{
    CURLcode res = CURLE_OK;
    int nCode = 0;

    if(NULL == curl || NULL == curl_params || NULL == curl_rec)
    {
        EPRINT("delete_msg curl or curl_params or curl_rec ptr is null \n");
        return -1;         //CURL_PARAMS指针为NULL
    }

    //发送数据,以及发送方式
    curl_easy_setopt(curl,CURLOPT_CUSTOMREQUEST,"DELETE");

    //设置消息头
    struct curl_slist *headers = NULL;
    if(FORMAT_XML == curl_params->format || FORMAT_JSON == curl_params->format)
    {
        curl_set_headers(curl, curl_params->format, &headers);
    }

    //CURL公共操作方式
    nCode = message_public_method(curl, curl_params);
    if(0 != nCode)
    {
        //释放头结构体
        if(NULL != headers)
        {
            curl_slist_free_all(headers);
            headers = NULL;
        }

        EPRINT("delete_msg call message_public_method failure \n");
        return -1;
    }

    // 设置回调函数
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, http_data_writer);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)curl_rec);
    res = curl_easy_perform(curl);

    //释放头结构体
    if(NULL != headers)
    {
        curl_slist_free_all(headers);
        headers = NULL;
    }

    //处理curl返回值
    nCode = dealResCode(curl, res);
    if(0 > nCode)
    {
        EPRINT("deal response code error \n");
    }

    //返回标识码
    return nCode;

}


/*
    * 通过post的方式操作
    * 参数1: curl指针
    * 参数2: curl参数结构体
    * 参数3: 要发送的数据
    * 参数4: 返回的数据
    * 返回值int, 0表示成功, 1表示超时,其他表示失败
*/
static int post_msg(CURL* curl,
                    st_curl_params* curl_params,
                    const char* msg,
                    st_curl_rec* curl_rec)
{
    CURLcode res = CURLE_OK;
    int nCode = 0;

    if(NULL == curl || NULL == curl_params || NULL == curl_rec)
    {
        EPRINT("post_msg curl or curl_params or curl_rec ptr is null \n");
        return -1;       //CURL_PARAMS指针为NULL
    }

    //发送数据,以及发送方式
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    if(NULL != msg && '\0' != msg[0])
    {
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, msg);
    }
    else
    {
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
    }

    //设置消息头
    struct curl_slist *headers = NULL;
    if(FORMAT_XML == curl_params->format || FORMAT_JSON == curl_params->format)
    {
        curl_set_headers(curl, curl_params->format,  &headers);
    }

    //CURL公共操作方式
    nCode = message_public_method(curl, curl_params);
    if(0 != nCode)
    {
        //释放头结构体
        if(NULL != headers)
        {
            curl_slist_free_all(headers);
            headers = NULL;
        }

        EPRINT("post_msg call message_public_method failure \n");
        return -1;
    }

    // 设置回调函数
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, http_data_writer);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)curl_rec);
    res = curl_easy_perform(curl);

    //释放头结构体
    if(NULL != headers)
    {
        curl_slist_free_all(headers);
        headers = NULL;

    }

    //处理curl返回值
    nCode = dealResCode(curl, res);
    if(0 > nCode)
    {
        EPRINT("deal response code error \n");
    }

    //返回标识码
    return nCode;

}


/*
    * 通过get的方式操作
    * 参数1: curl结构体
    * 参数2: curl参数结构体
    * 参数3: 要发送的数据, 此方式可为空
    * 参数4: 返回的数据结构体
    * 返回值int, 0表示成功, 1表示超时,其他表示失败
*/
static int get_msg(CURL* curl,
                   st_curl_params* curl_params,
                   const char* msg,
                   st_curl_rec* curl_rec)
{
    CURLcode res = CURLE_OK;
    int nCode = 0;

    if(NULL == curl || NULL == curl_params || NULL == curl_rec)
    {
        EPRINT("get_msg curl or curl_params or msg ptr is null \n");
        return -1;       //CURL_PARAMS指针为NULL
    }

    //设定传输方式
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);

    //设置消息头
    struct curl_slist *headers = NULL;
    if(FORMAT_XML == curl_params->format || FORMAT_JSON == curl_params->format)
    {
        curl_set_headers(curl, curl_params->format, &headers);
    }

    //CURL公共操作方式
    nCode = message_public_method(curl, curl_params);
    if(0 != nCode)
    {
        //释放头结构体
        if(NULL != headers)
        {
            curl_slist_free_all(headers);
        }

        EPRINT("get_msg call message_public_method failure \n");
        return -1;
    }

    // 设置回调函数
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, http_data_writer);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)curl_rec);
    res = curl_easy_perform(curl);

    //释放头结构体
    if(NULL != headers)
    {
        curl_slist_free_all(headers);
        headers = NULL;
    }

    //处理curl返回值
    nCode = dealResCode(curl, res);
    if(0 > nCode)
    {
        EPRINT("deal response code error \n");
    }

    //返回成功
    return nCode;

}


/*
    * 进行所有CURL开始之前的，全局变量初始化，放在主线程中
    * 返回值为int, 0表示成功，其他表示失败
*/
int curl_global_init_resource()
{

    if(0 == s_global_init_status)
    {

        if(CURLE_OK == curl_global_init(CURL_GLOBAL_ALL))
        {
            //返回成功
            s_global_init_status = 1;
            return 0;
        }
        else
        {
            EPRINT("curl_global_init error(%d)\n", errno);
            return -1;                  //CURL全局资源初始化失败
        }

    }

    return 0;
}


/*
    * 进行所有CURL开始结束的，全局变量初始化，放在主线程中
    * 返回值为int, 0表示成功，其他表示失败
*/
int curl_global_cleanup_resource()
{

    if(1 == s_global_init_status)
    {
        curl_global_cleanup();
        s_global_init_status = 0;
    }

    return 0;
}

/*
    * curl参数初始化
    * 1：ip地址
    * 2：url路径
    * 3：端口
    * 4：用户名
    * 5：验证密码
    * 6：数据格式(0默认,1为xml,2为json)
*/
int curl_init_params(st_curl_params* curl_params,
                     const char* ip,
                     const char* url_path,
                     const int port,
                     const char* user,
                     const char* pwd,
                     const int format)
{
    if(NULL == curl_params || NULL == ip)
    {
        EPRINT("curl_init_params curl_params or ip ptr is null \n");
        return -1;
    }
    memset(curl_params, 0, sizeof(*curl_params));            //初始化整个结构体
    strncpy(curl_params->ip, ip, sizeof(curl_params->ip)-1);
    curl_params->port = port;
    curl_params->format = format;

    if(NULL != url_path)
    {
        strncpy(curl_params->url_path, url_path, sizeof(curl_params->url_path)-1);
    }

    if((NULL != user) && (NULL != pwd))
    {
        strncpy(curl_params->user, user, sizeof(curl_params->user)-1);
        strncpy(curl_params->pwd, pwd, sizeof(curl_params->pwd)-1);
    }

    return 0;

}


/*
    * 数据发送方式
    * 参数1: curl指针
    * 参数2：curl参数结构体
    * 参数3：要发送的数据
    * 参数4：发送的方法：0使用GET, 1使用POST, 2使用PUT, 3使用DELETE,
    * 参数5：返回的数据信息,无需初始化,内部初始化
    * 返回值int, 0表示成功, 1表示超时,其他表示失败
*/
int send_msg(CURL* curl,
             st_curl_params* curl_params,
             const char* msg,
             const int method,
             st_curl_rec* curl_rec)
{
    if(NULL == curl || NULL == curl_params || NULL == curl_rec)
    {
        EPRINT("send_msg curl or curl_params or curl_rec ptr is null \n");
        return -1;
    }

    int nCode = -1;
    memset(curl_rec, 0, sizeof(st_curl_rec));
    switch(method)
    {
        case METHOD_GET:        //使用GET方法传送数据
        {
            nCode = get_msg(curl, curl_params, msg, curl_rec);
            return nCode;
        }
        case METHOD_POST:       //使用POST方法传送数据
        {
            nCode = post_msg(curl, curl_params, msg, curl_rec);
            return nCode;
        }
        case METHOD_PUT:        //使用PUT方法传送数据
        {
            nCode = put_msg(curl, curl_params, msg, curl_rec);
            return nCode;
        }
        case METHOD_DELETE:    //使用DELETE方法传送数据
        {
            nCode = delete_msg(curl, curl_params, msg, curl_rec);
            return nCode;
        }
        default:
        {
            EPRINT("send_msg method error\n");
            return -1;
        }
    }

    return -1;
}


/*
    * 设置发送路径
    * 参数1：cuel参数结构体
    * 参数2：url路径
*/
void set_url_path(st_curl_params* curl_params, char* url_path)
{
    strncpy(curl_params->url_path, url_path, sizeof(curl_params->url_path)-1);
}

/*
    * 设置连接超时时间
    * 参数1：cuel参数结构体
    * 参数2：时间秒数
*/
void set_connect_timeout(st_curl_params* curl_params, int connect_timeout)
{
    curl_params->connect_timeout =  connect_timeout;
}


/*
    * 设置传输超时时间
    * 参数1：cuel参数结构体
    * 参数2：时间秒数
*/
void set_timeout(st_curl_params* curl_params, int timeout)
{
    curl_params->timeout =  timeout;
}


/*
    * 下载文件
    * 参数1: curl指针
    * 参数2：参数结构体
    * 参数3：文件存放名
    * 返回值int, 0表示成功, 1表示超时,其他表示失败
*/
int download_file(CURL* curl, st_curl_params* curl_params, const char* filename)
{
    CURLcode res = CURLE_OK;
    FILE* pFile = NULL;
    int nCode = 0;

    if(NULL == curl || NULL == curl_params || NULL == filename || '\0' == filename[0])
    {
        EPRINT("download_file curl or curl_params or filename ptr is null \n");
        return -1;       //CURL_PARAMS指针为NULL
    }

    pFile = fopen(filename, "w");         //打开文件,返回结果用文件存储
    if (NULL == pFile)
    {
        EPRINT("download_file open file error(%d), %s\n", errno, filename);
        return -1;      //打开文件失败
    }

    //设定传输方式
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);

    //设置消息头
    struct curl_slist *headers = NULL;
    if(FORMAT_XML == curl_params->format || FORMAT_JSON == curl_params->format)
    {
        curl_set_headers(curl, curl_params->format, &headers);
    }

    //CURL公共操作方式
    nCode = message_public_method(curl, curl_params);
    if(0 != nCode)
    {
        //释放头结构体
        if(NULL != headers)
        {
            curl_slist_free_all(headers);
            headers = NULL;
        }

        if(NULL != pFile)
        {
            fclose(pFile);
            pFile = NULL;
        }

        EPRINT("download_file call message_public_method failure \n");
        return -1;
    }

    // 设置回调函数
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, http_write_file);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, pFile);
    res = curl_easy_perform(curl);

    //释放资源
    {
        //释放头结构体
        if(NULL != headers)
        {
            curl_slist_free_all(headers);
            headers = NULL;
        }

        if(NULL != pFile)
        {
            fclose(pFile);
            pFile = NULL;
        }
    }

    //处理curl返回值
    nCode = dealResCode(curl, res);
    if(0 > nCode)
    {
        EPRINT("deal response code error \n");
    }

    //返回成功
    return nCode;

}

/*
    * 从文件中读取内容post出去
    * 参数1: curl指针
    * 参数2：cuel参数结构体
    * 参数3：文件名
    * 参数4：返回数据,无需初始化,内部初始化
    * 返回值int, 0表示成功, 1表示超时,其他表示失败
*/
int upload_file_content(CURL* curl,
                        st_curl_params* curl_params,
                        const char* filename,
                        st_curl_rec* curl_rec)
{
    CURLcode res = CURLE_OK;
    FILE* pFile = NULL;
    struct stat file_info;
    curl_off_t fsize;
    int nCode = 0;

    if(NULL == curl || NULL == curl_params || NULL == filename || NULL == curl_rec)
    {
        EPRINT("upload_file_content curl or curl_params or filename or curl_rec ptr is null \n");
        return -1;            //CURL_PARAMS指针为NULL
    }

    if(stat(filename, &file_info))      //文件大小
    {
        EPRINT("upload_file_content get file info error(%d), %s\n", errno, filename);
        return -1;
    }
    fsize = (curl_off_t)file_info.st_size;

    pFile = fopen(filename, "rb");      //打开文件,返回结果用文件存储
    if (NULL == pFile)
    {
        EPRINT("upload_file_content open file error(%d), %s\n", errno, filename);
        return -1;                      //打开文件失败
    }

    //设定传输方式
    curl_easy_setopt(curl, CURLOPT_POST, 1);

    //设置消息头
    struct curl_slist *headers = NULL;
    if(FORMAT_XML == curl_params->format || FORMAT_JSON == curl_params->format)
    {
        curl_set_headers(curl, curl_params->format, &headers);
    }

    //CURL公共操作方式
    nCode = message_public_method(curl, curl_params);
    if(0 != nCode)
    {
        //释放头结构体
        if(NULL != headers)
        {
            curl_slist_free_all(headers);
            headers = NULL;
        }

        if(NULL != pFile)
        {
            fclose(pFile);
            pFile = NULL;
        }

        EPRINT("upload_file_content call message_public_method failure \n");
        return -1;
    }

    // 设置回调函数
    memset(curl_rec, 0, sizeof(st_curl_rec));
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, http_read_file);
    curl_easy_setopt(curl, CURLOPT_READDATA, pFile);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (curl_off_t)fsize);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, http_data_writer);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)curl_rec);

    res = curl_easy_perform(curl);

    //释放资源
    {
        //释放头结构体
        if(NULL != headers)
        {
            curl_slist_free_all(headers);
            headers =NULL;
        }

        if(NULL != pFile)
        {
            fclose(pFile);
            pFile = NULL;
        }
    }

    //处理curl返回值
    nCode = dealResCode(curl, res);
    if(0 > nCode)
    {
        EPRINT("deal response code error \n");
    }

    //返回成功
    return nCode;

}



/*
    * 宏定义上传文件相关信息
*/
#define FILE_NAME_MAX_SIZE      (128)

/*
    * 从文件全路径中获取文件名指针
    * 返回文件名地址
*/
static const char* get_file_name_ptr(const char *path)
{
    if(!path)
    {
        return NULL;
    }

    //找最后一个斜杠/
    char *pname = strrchr(path, '/');
    if(!pname)
    {
        //没找到斜杠,则认为path就是文件名
        return path;
    }

    //找到最后一个斜杠, 反回指针加1
    return (char*)(pname + 1);
}


/*
    * 上传文件
    * 参数1: curl指针
    * 参数2: cuel参数结构体
    * 参数3: 文件名
    * 参数4: 返回数据,无需初始化,内部初始化
    * 返回值int, 0表示成功, 1表示超时,其他表示失败
*/
int upload_file(CURL* curl,
                st_curl_params* curl_params,
                const char* file_fullname,
                st_curl_rec* curl_rec)
{
    CURLcode res = CURLE_OK;
    int nCode = 0;
    struct curl_httppost *formpost = NULL;
    struct curl_httppost *lastptr = NULL;
    struct curl_slist *headerlist = NULL;
    static const char buf[] = "Expect:";

    //参数合法性检查
    if(NULL == curl || NULL == curl_params || NULL == file_fullname || '\0' == file_fullname[0] || NULL == curl_rec)
    {
        EPRINT("upload_file_content curl or curl_params or file_fullname or curl_rec ptr is null \n");
        return -1;            //CURL_PARAMS指针为NULL
    }

    //获取文件名
    const char* file_name = get_file_name_ptr(file_fullname);
    if(NULL == file_name || '\0' == file_name[0])
    {
        EPRINT("uploadFile call get_file_name failure, file_fullname=%s \n", file_fullname);
        return -1;
    }
    EPRINT("file_name=%s \n", file_name);

    //CURL公共操作方式
    nCode = message_public_method(curl, curl_params);
    if(0 != nCode)
    {
        EPRINT("upload_file_content call message_public_method failure \n");
        return -1;
    }

    /*
    Fill in the file upload field. This makes libcurl load data from
     the given file name when curl_easy_perform() is called.
    */
    curl_formadd(&formpost,
                 &lastptr,
                 CURLFORM_COPYNAME, "sendfile",
                 CURLFORM_FILE, file_fullname,
                 CURLFORM_END);

    /* Fill in the filename field */
    curl_formadd(&formpost,
                 &lastptr,
                 CURLFORM_COPYNAME, "filename",
                 CURLFORM_COPYCONTENTS, file_name,
                 CURLFORM_END);

    /* Fill in the submit field too, even if this is rarely needed */
    curl_formadd(&formpost,
                 &lastptr,
                 CURLFORM_COPYNAME, "submit",
                 CURLFORM_COPYCONTENTS, "send",
                 CURLFORM_END);

    headerlist = curl_slist_append(headerlist, buf);

    /* only disable 100-continue header if explicitly requested */
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
    curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);

    //返回值
    memset(curl_rec, 0, sizeof(st_curl_rec));
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, http_data_writer);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)curl_rec);


    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);

    /* then cleanup the formpost chain */

    if(NULL != formpost)
    {
        curl_formfree(formpost);
        formpost = NULL;
    }

    /* free slist */
    if(NULL != headerlist)
    {
        curl_slist_free_all(headerlist);
        headerlist = NULL;
    }

    //处理curl返回值
    nCode = dealResCode(curl, res);
    if(0 > nCode)
    {
        EPRINT("deal response code error \n");
    }

    return nCode;
}
