#define MYERROR
#include <my/debug.info.h>

#define MAXLINE 256

int main(int argc, char **argv)
{
    char buf[MAXLINE];
    memset(buf, 0, sizeof(char) * MAXLINE);


    int sockfd, connfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        PRINTEXIT("socket error");


    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(13);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    //?

    bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));

    //    listen(sockfd,LISTENQ);
    listen(sockfd, 5);

    time_t tick;
    while (1)
    {
        connfd = accept(sockfd, (struct sockaddr *)NULL, NULL);
        tick = time(NULL);
        snprintf(buf, MAXLINE, "%.24s\r\n", ctime(&tick));
        write(connfd, buf, sizeof(buf));
        close(connfd);
    }
    return 0;
}