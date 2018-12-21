//
// Created by shanlovana on 18-12-20.
//
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "smarthttp.c"

//服务器main函数
int main() {
    int server_sock = 1;
    u_short port = 4000;
    int client_sock = -1;
    struct sockaddr_in client_name;
    socklen_t client_name_len = sizeof(client_name);
    pthread_t new_thread;

    //建立监听套接字，在对应的端口建立http服务
    server_sock = startup(&port);
    printf("http running on port %d\n", port);
    // 进入循环，服务器通过调用accept等待客户端的连接，Accept会以阻塞的方式运行，直到
    // 有客户端连接才会返回。连接成功后，服务器启动一个新的线程来处理客户端的请求，处理
    // 完成后，重新等待新的客户端请求。
    int a;
    while (a) {
        // 返回一个已连接套接字，套接字收到客户端连接请求
        client_sock = accept(server_sock, (struct sockaddr *) &client_name, &client_name_len);
        if (client_sock == -1) {
            error_die("accept");
        }
        // 派生线程用accept_request函数处理新请求。
        /* accept_request(client_sock); */
        if (pthread_create(&new_thread, NULL, (void *) accept_request, (void *) &client_sock) != 0) {
            perror("pthrea_create");
        }
    }
    //出现意外，关闭socket
    close(server_sock);

    return 0;

}