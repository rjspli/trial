#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 128

void err_exit(const char *err){
    perror(err);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd = 0, msg_count = 0;
    uint16_t port;
    char buffer[BUF_SIZE] = {0,};
    struct sockaddr_in server_addr;
    if(argc != 3){
        printf("\n Usage: %s server_ip port\n",argv[0]);
        return 1;
    }
    port = atoi(argv[2]);
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_exit("socket error");
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_aton(argv[1], (struct in_addr*)&server_addr.sin_addr);
    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        err_exit("connect error");
    while(1){
        msg_count = recv(sockfd, buffer, BUF_SIZE, 0);
        if(msg_count < 0) err_exit("recv error");
        printf("(msg from server):%s\n", buffer);
        while(1){
            printf("message:");
            fgets(buffer, BUF_SIZE, stdin);
            if(strlen(buffer) >= 128 - 1)
                printf("message too large\n");
            else 
                break;
        }
        buffer[strlen(buffer) - 1] = '\0';
        msg_count = send(sockfd, buffer, strlen(buffer) + 1, 0);
        if(msg_count < 0)err_exit("send error");
    }
    shutdown(sockfd, SHUT_RDWR);
    return 0;
}