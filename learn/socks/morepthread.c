#define MYERROR
#define __USE_POSIX
#include <my/debug.info.h>
//多线程
#define MAXLINE 256
#define PORT 4000
#define MAXCLIENT 10
struct ClientAddrPort
{
    struct sockaddr_in addr;
    int sock;
};
void *service(void *CAP)
{
    struct ClientAddrPort cs = *(struct ClientAddrPort *)CAP;
    struct sockaddr_in addr = cs.addr;
    int sockfd = cs.sock;
    char buf[MAXLINE];
    memset(buf, 0, sizeof(char) * MAXLINE);
    time_t tick;
    while (1)
    {

        read(sockfd, buf, MAXLINE);

        printf("read:%s", buf);
        printf("from %s %d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));

        if (strncmp(buf, "exit", 4) == 0)
        {
            break;
        }
        memset(buf, 0, sizeof(char) * MAXLINE);
        tick = time(NULL);
        snprintf(buf, MAXLINE, "%.24s\r\n", ctime(&tick));
        write(sockfd, buf, sizeof(buf));
        memset(buf, 0, sizeof(char) * MAXLINE);
    }
    printf("one pthread sleep and exit\n");
  
    close(sockfd);  sleep(3);
    pthread_exit(0);
    return NULL;
}
/*void *client(void *sock)
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
}*/
void CatChildPthread(int sig)
{
    if (sig == SIGCHLD)
    {
        //wait(NULL);
        printf("detached ");
        sleep(5);
        return;
    }
}
int main(int argc, char **argv)
{

    int sockfd, cfd;
    pthread_t thread[MAXCLIENT];
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) //创建套接字
        PRINTEXIT("socket error");
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr)); //自定义addr结构
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)); //绑定
    listen(sockfd, 4);                                    //监听
    socklen_t slen = sizeof(struct sockaddr);
    struct ClientAddrPort cs[MAXCLIENT];
    int i = 0;
    // sigset_t sig;
    // sigemptyset(&sig);
    // sigaddset(&sig, SIGCHLD);
    // struct sigaction new;
    // new.sa_handler = CatChildPthread; //执行函数名
    // new.sa_flags = SA_SIGINFO;
    // sigemptyset(&new.sa_mask); //设置屏蔽字S
    // sigaction(SIGCHLD, &new, NULL);
    //signal(SIGCHLD, CatChildPthread);
    while (1)
    {
        memset(&cs[i], 0, sizeof(struct ClientAddrPort));
        cfd = accept(sockfd, (struct sockaddr *)&addr, &slen); //accept
        cs[i].addr = addr;
        cs[i].sock = cfd;
        pthread_create(&thread[i], NULL, service, (void *)&cs[i]);
        pthread_detach(thread[i]);
        i++;
        if (i > MAXCLIENT)
        {
            printf("max client\n");
            break;
        }
    }
    return 0;
}