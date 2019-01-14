//
// Created by ubuntu on 18-12-26.
//

#include <stdio.h>
#include <string.h>
#include "cluster_curl.h"
#include <cjson/cJSON.h>

#define DPRINT printf
#define EPRINT printf

void test_post_method();

void test_get_method();

void down_file_method();

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    size_t written = fwrite(ptr, size, nmemb, (FILE *) stream);
    return written;
}

int getRequest() {
    int nCode = -1;

    //全局资源初始化，放在主线程
    nCode = curl_global_init_resource();
    down_file_method();
    //test_post_method();
    //test_get_method();
    //全局资源清除，放在主线程中
    nCode = curl_global_cleanup_resource();
    return 0;
}


/*
	* 通过GET发送数据示例,delete类似
*/
void test_get_method() {
    int nCode = -1;

    //初始化st_curl_params相关参数
    char *ip = "10.6.191.177";
    char *url_path = "/cserver/login/get";
    int port = 8099;
    char *user = "USER";
    char *pwd = "PWD";
    int format = FORMAT_XML;
    st_curl_params curl_params;
    curl_init_params(&curl_params, ip, url_path, port, user, pwd, format);


    //设置返回数据结构体
    st_curl_rec curl_rec;


    //使用GET方式发送数据method = 0,数据格式为默认format = 0,msg发送数据为空,curl_rec为返回数据
    char *msg = "{\"user\":\"user\",\"pwd\":\"pwd\"}";
    int method = METHOD_GET;
    CURL *curl = NULL;
    curl = curl_init_resource();
    nCode = send_msg(curl, &curl_params, msg, method, &curl_rec);
    DPRINT("get:\n%s\nsize:%d\n", curl_rec.rec, curl_rec.len);
    curl_release_resource(curl);

}

/*
	* 通过POST发送数据示例，put类似
*/
void test_post_method() {
    int nCode = -1;

    //初始化st_curl_params关参数 ,数据格式为json即format = 2
    char *ip = "10.6.191.177";
    char *url_path = "/cserver/login/get";
    int port = 8099;
    char *user = "USER";
    char *pwd = "PWD";
    char *post_str = NULL;
    int format = FORMAT_JSON;
    st_curl_params curl_params;
    curl_init_params(&curl_params, ip, url_path, port, user, pwd, format);

    //设置返回数据结构体
    st_curl_rec curl_rec;

    //使用POST方式发送数据method = 1，msg发送数据,curl_rec为返回数据
    int method = METHOD_POST;
    //存放要发送的数据，下列为json数据
    cJSON *root = cJSON_CreateObject();

    cJSON_AddStringToObject(root, "user", "为所欲为");
    cJSON_AddStringToObject(root, "pwd", "hkcw3cjbc");
    post_str = cJSON_Print(root);
    cJSON_Delete(root);
    root = NULL;

    CURL *curl = NULL;
    curl = curl_init_resource();
    nCode = send_msg(curl, &curl_params, post_str, method, &curl_rec);
    DPRINT("post:\n%s\nsize:%d\n", curl_rec.rec, curl_rec.len);
    curl_release_resource(curl);
}


void down_file_method() {
    static const char *pagefilename = "/home/shanlovana/HWIDGen_CN.exe";
    FILE *pagefile;
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curl_handle = NULL;
    char *DOWNLOADURL = "http://plb5lb7wm.bkt.clouddn.com/HWIDGen_CN.exe";

    /* init the curl session */
    curl_handle = curl_easy_init();

    /* set URL to get here */
    curl_easy_setopt(curl_handle, CURLOPT_URL, DOWNLOADURL);

    /* Switch on full protocol/debug output while testing */
    curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);

    /* disable progress meter, set to 0L to enable and disable debug output */
    curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 0L);

    /* send all data to this function  */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

    /* open the file */
    pagefile = fopen(pagefilename, "wb");
    if (pagefile) {

        /* write the page body to this file handle */
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, pagefile);

        /* get it! */
        curl_easy_perform(curl_handle);

        /* close the header file */
        fclose(pagefile);
    }

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);

    curl_global_cleanup();

}