//
// Created by ubuntu on 18-12-26.
//

#include <stdio.h>
#include <string.h>
#include "cluster_curl.h"

#define DPRINT printf
#define EPRINT printf

/*
	* 通过POST发送数据示例，GET类似
*/
void test_post_method() {
    int nCode = -1;

    //初始化st_curl_params关参数 ,数据格式为json即format = 2
    char *ip = "220.181.57.216";
    char *url_path = NULL;
    int port = 80;
    char *user = "USER";
    char *pwd = "PWD";
    int format = FORMAT_JSON;
    st_curl_params curl_params;
    curl_init_params(&curl_params, ip, url_path, port, user, pwd, format);

    //设置返回数据结构体
    st_curl_rec curl_rec;

    //使用POST方式发送数据method = 1，msg发送数据,curl_rec为返回数据
    int method = METHOD_GET;
    //存放要发送的数据，下列为json数据
    char *msg = "{\"UserName\":\"user\",\"UserPwd\":\"pwd\"}";
    CURL *curl = NULL;
    curl = curl_init_resource();
    nCode = send_msg(curl, &curl_params, "", method, &curl_rec);
    DPRINT("post:\n%s\nsize:%d\n", curl_rec.rec, curl_rec.len);
    curl_release_resource(curl);

}

int getRequest() {
    int nCode = -1;

    //全局资源初始化，放在主线程
    nCode = curl_global_init_resource();

    test_post_method();

    //全局资源清除，放在主线程中
    nCode = curl_global_cleanup_resource();
    return 0;
}


