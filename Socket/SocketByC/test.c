/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Mon 13 May 2024 06:35:09 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "./network.h"

void echo_server(const int port) {
   int server_listen = socket_create(8080);
    if (server_listen < 0) {
        perror("socket_create");
        return ;
    }
    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    int cli_fd;
    memset(&cli_addr, 0, cli_len);
    cli_fd = accept(server_listen, (struct sockaddr *)&cli_addr, &cli_len);
    if (cli_fd < 0){
        perror("accept");
        return ;
    }
   
    printf("连接成功\n");
    while (1) {
        char buff[1024] = {0};
        ssize_t recv_size = recv(cli_fd, buff, sizeof(buff), 0);
        if (recv_size < 0) {
            perror("recv_size");
            return ;
        }
        if (recv_size == 0) {
            printf("disconnect\n");
            break;
        }
        printf("recv [%lu] : %s\n", recv_size, buff);
        send(cli_fd, buff, strlen(buff), 0);//传输信息
    }
    return ;
}

int main() {

    echo_server(8080);//echo服务器

    return 0;
}
