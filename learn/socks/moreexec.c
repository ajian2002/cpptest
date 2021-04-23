#define MYERROR
#include <my/debug.info.h>

#define MAXLINE 256
void *service(void *sock)
{
    int sockfd = *(int *)sock;
    char buf[MAXLINE];
    memset(buf, 0, sizeof(char) * MAXLINE);

    int connfd;
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(13);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sockfd, (struct sockaddr *)&addr, NULL);

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
    return NULL;
}
void *client(void *sock)
{
    char s1[20];
wwc:
    memset(s1, 0, sizeof(char) * 20);
    int sockfd = *(int *)sock;
    char buf[MAXLINE];
    memset(buf, 0, sizeof(char) * MAXLINE);

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(13);
    printf("input ip:");
    scanf("%s", s1);
    if (inet_pton(AF_INET, s1, &addr.sin_addr) <= 0)
        PRINTEXIT("inet");
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        PRINTEXIT("connect error");
    int n = 0;
    while ((n = read(sockfd, buf, MAXLINE)) > 0)
    {
        buf[n] = 0;
        printf("%s\n", buf);
        if (fputs(buf, stdout) == EOF)
            PRINTEXIT("fputs");
    }
    if (n < 0)
        PRINTEXIT("read");
    close(sockfd);
    sleep(3);
    goto wwc;
    return NULL;
}
int main(int argc, char **argv)
{

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        PRINTEXIT("socket error");
    // pthread_t thread1, thread2;
    // pthread_create(&thread1, NULL, (void *)service, &sockfd);
    // pthread_create(&thread2, NULL, client, &sockfd);
    // execvp(service, &sockfd);
    sleep(20);
    return 0;
}