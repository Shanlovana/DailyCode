//
// Created by android on 19-8-9.
//

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define PORT 3040            //目标地址端口号
#define ADDR "10.6.191.177" //目标地址IP,ifconfig查看自己主机ip

int main2() //若想编译运行，请将名称改为main
{
    int iSocketFD = 0; //socket句柄
    unsigned int iRemoteAddr = 0;
    struct sockaddr_in stRemoteAddr = {0}; //对端，即目标地址信息
    socklen_t socklen = 0;
    char buf[4096] = {0}; //存储接收到的数据

    iSocketFD = socket(AF_INET, SOCK_STREAM, 0); //建立socket
    if (0 > iSocketFD) {
        printf("创建socket失败！\n");
        return 0;
    }

    stRemoteAddr.sin_family = AF_INET;
    stRemoteAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, ADDR, &iRemoteAddr);
    stRemoteAddr.sin_addr.s_addr = iRemoteAddr;

    //连接方法： 传入句柄，目标地址，和大小
    if (0 > connect(iSocketFD, (void *) &stRemoteAddr, sizeof(stRemoteAddr))) {
        printf("连接失败！\n");
        //printf("connect failed:%d",errno);//失败时也可打印errno
    } else {
        printf("连接成功！\n");
        recv(iSocketFD, buf, sizeof(buf), 0); ////将接收数据打入buf，参数分别是句柄，储存处，最大长度，其他信息（设为0即可）。 
        printf("Received:%s\n", buf);
    }

    close(iSocketFD);//关闭socket
    return 0;
}
