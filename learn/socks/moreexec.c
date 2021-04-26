#define MYERROR
#include <my/debug.info.h>
//多进程
#define MAXLINE 256
#define PORT 5000
#define MAXCLIENT 10
struct ClientAddrPort
{
    struct sockaddr_in addr;
    int sock;
};
void CatChildExec(int sig)
{
    if (sig == SIGCHLD)
    {
        while (waitpid(0, NULL, WNOHANG))
            ;
    }
}
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
        int len = 0;
        len = read(sockfd, buf, MAXLINE);

        if (len == 0)
        {
            break;
        }
        printf("len:%d\n", len);

        printf("read:%s", buf);
        printf("from %s %d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));

        if (strncmp(buf, "exit", 4) == 0)
            break;

        memset(buf, 0, sizeof(char) * MAXLINE);
        tick = time(NULL);
        snprintf(buf, MAXLINE, "%.24s\r\n", ctime(&tick));
        write(sockfd, buf, sizeof(buf));
        memset(buf, 0, sizeof(char) * MAXLINE);
    }

    close(sockfd);
    return NULL;
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
    //开启端口复用
    int op = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, (void *)&op, sizeof(op));

    bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)); //绑定
    listen(sockfd, 4);                                    //监听
    socklen_t slen = sizeof(struct sockaddr);
    struct ClientAddrPort cs[MAXCLIENT];
    int i = 0;
    int pid[MAXCLIENT];
    // sigset_t sig;
    // sigemptyset(&sig);
    // sigaddset(&sig, SIGCHLD);
    // struct sigaction new;
    // new.sa_handler = CatChildPthread; //执行函数名
    // new.sa_flags = SA_SIGINFO;
    // sigemptyset(&new.sa_mask); //设置屏蔽字S
    // sigaction(SIGCHLD, &new, NULL);
    signal(SIGCHLD, CatChildExec);
    while (1)
    {
        memset(&cs[i], 0, sizeof(struct ClientAddrPort));
        cfd = accept(sockfd, (struct sockaddr *)&addr, &slen); //accept
        cs[i].addr = addr;
        cs[i].sock = cfd;

        if (i > MAXCLIENT)
        {
            printf("max client\n");
            exit(-1);
        }
        pid[i] = fork();
        if (pid[i] == 0)
        {
            close(sockfd);
            service((void *)&cs[i]);
            exit(0);
        }
        else if (pid < 0)
        {
            PRINTEXIT("fork error");
        }
        else
        {
            close(cfd);
            i++;
            continue;
        }
    }
    return 0;
}