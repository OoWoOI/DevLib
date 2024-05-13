/*************************************************************************
	> File Name: network.c
	> Author: 
	> Mail: 
	> Created Time: Mon 13 May 2024 06:06:55 PM CST
 ************************************************************************/


#include "./network.h"

int socket_create(const int port) {
    int sockfd;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
        return -1;
    }
    
    
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;//监听所有网络接口的连接请求
    addr.sin_port = htons(port);
    
    int val = 1;
    //以下调用setsockopt设置地址重用
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(int)) < 0) {
        return -1;
    }

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        return -1;
    }
    
    //监听连接
    if (listen(sockfd, 20) < 0) {
        return -1;
    }
    
    return sockfd;
}

int socket_connect(const char *ip, const int port) {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }

    struct sockaddr_in addr;//套接字地址结构体
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port); 

    //连接
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        return -1;
    }
    
    return sockfd;
}

int socket_connect_timeout(const char *ip, const int port, time_t time_val) {
    
    int sockfd;

    return sockfd;
}

