//
// Created by ubuntu on 18-12-26.
//

/*
    * curl的封装，有以下操作：
    * 1.发送信息：get、post、put、delete
    * 2.上传文件处理
    * 3.下载文件
*/

#ifndef CCODES_CLUSTER_CURL_H
#define CCODES_CLUSTER_CURL_H

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <stdbool.h>

#define  EPRINT  printf
#define  DPRINT  printf

/*
    * 宏定义curl个参数大小
*/
#define MAX_IP_LEN        (32)             //ip地址最大长度
#define MAX_URL_PATH_LEN  (128)            //url路径最大长度
#define MAX_USER_LEN      (64)             //用户名最大长度
#define MAX_PWD_LEN       (64)             //验证密码最大长度

#define MAX_URL_LEN       (168)            //url最大长度
#define MAX_REC_LEN       (20480)          //返回数据最大长度
#define MAX_TEMP_LEN      (128)            //临时变量最大长度

/*
    * 宏定义发送信息方法
*/
#define METHOD_GET         0                //0为GET方法
#define METHOD_POST        1                //1为POST方法
#define METHOD_PUT         2                //2为PUT方法
#define METHOD_DELETE      3                //3为DELETE方法

/*
    * 宏定义数据格式
*/
#define FORMAT_DEFAULT     0                //0为默认数据格式
#define FORMAT_XML         1                //1为xml数据格式
#define FORMAT_JSON        2                //2为json数据格式


/*
    * 宏定义超时时间
*/
#define C_CONNECT_DEFAULT_TIMEOUT  10  //连接最长时间
#define C_DEFAULT_TIMEOUT          600 //传输最长时间



/*
    * CLUSTER_CURL
    * 0表示成功, -1表示失败
*/

/*
    * curl结构体，包含相关参数
*/
typedef struct st_curl_params {
    char ip[MAX_IP_LEN];                    //curl请求的ip
    char url_path[MAX_URL_PATH_LEN];        //url路径
    int port;                              //curl请求ip的端口
    char user[MAX_USER_LEN];                //需要对方验证时使用，请求对方需要的用户名
    char pwd[MAX_PWD_LEN];                  //需要对方验证时使用，请求对方需要的密码
    int format;                            //传送数据格式
    int connect_timeout;                   //连接超时
    int timeout;                           //传输最长时间
} st_curl_params;

/*
    * 返回数据结构体，包含相关参数
*/
typedef struct st_curl_rec {
    char rec[MAX_REC_LEN];                  //curl返回数据数组空间大小,最大为10kb
    int len;                               //curl实际返回数据大小
} st_curl_rec;

/*
    * 外部使用接口
*/

/*
    * 进行所有CURL开始之前，全局变量初始化，放在主线程中
*/
extern int curl_global_init_resource();

/*
    * 进行所有CURL结束之前，全局资源释放，放在主线程中
*/
extern int curl_global_cleanup_resource();

/*
    * 进行单个线程CURL简单资源进行初始化
*/
extern CURL *curl_init_resource();

/*
    * 进行单个线程CURL简单资源进行释放
*/
extern int curl_release_resource(CURL *curl);

/*
    * curl参数初始化
*/
extern int curl_init_params(st_curl_params *curl_params,
                            const char *ip,
                            const char *url_path,
                            const int port,
                            const char *user,
                            const char *pwd,
                            const int format);

/*
    * 设置发送路径
*/
extern void set_url_path(st_curl_params *curl_params, char *url_path);

/*
    * 设置连接超时
*/
extern void set_connect_timeout(st_curl_params *curl_params, int connect_timeout);

/*
    * 设置传输超时
*/
extern void set_timeout(st_curl_params *curl_params, int timeout);

/*
    * 发送消息发送方式
*/
extern int send_msg(CURL *curl,
                    st_curl_params *curl_params,
                    const char *msg,
                    const int method,
                    st_curl_rec *curl_rec);

/*
    * 下载文件
*/
extern int download_file(CURL *curl, st_curl_params *curl_params, const char *filename);

/*
    * 从文件中读取内容post出去
*/
extern int upload_file_content(CURL *curl,
                               st_curl_params *curl_params,
                               const char *filename,
                               st_curl_rec *curl_rec);

/*
    * 上传文件
*/
extern int upload_file(CURL *curl,
                       st_curl_params *curl_params,
                       const char *file_fullname,
                       st_curl_rec *curl_rec);


#endif //CCODES_CLUSTER_CURL_H
