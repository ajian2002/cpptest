#define MYERROR
#include <my/debug.info.h>
#define MAXLINE 256
#define PORT 45454
//server
int main(int argc, char **argv)
{
    struct sockaddr_in severaddr;
    severaddr.sin_family = AF_INET;
    severaddr.sin_port = htons(PORT);
    severaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    int so = socket(AF_INET, SOCK_DGRAM, 0); //socket 协议

    bind(so, (struct sockaddr *)&severaddr, sizeof(struct sockaddr));

    //listen(so, 10); //TCP 专用

    struct sockaddr_in clientaddr;
    socklen_t len =sizeof(struct sockaddr_in);
    while (1)
    {
        //accept取消
        // if ((newso = accept(so, (struct sockaddr *)&clientaddr, &len)) < 0)
        // {
        //     PRINTEXIT("accept error");
        // }
        int n = 0;
        char buf[1000];
        char str[100];
        bzero(&buf, sizeof(buf));
        bzero(&str, sizeof(str));
        n = recvfrom(so, buf, MAXLINE, 0, (struct sockaddr *)&clientaddr, &len); //accept+read
        if (n == -1)
        {
            perror("recvfrom error");
        }
        printf("%s\n", buf);
        printf("client from %s %ld \n", inet_ntop(AF_INET, &clientaddr.sin_addr, str, sizeof(str)), ntohs(clientaddr.sin_port));

        n = sendto(so, buf, n, 0, (struct sockaddr *)&clientaddr, sizeof(struct sockaddr_in));
        if (n == -1)
        {
            perror("sendto error");
        }
    }
    close(so);

    return 0;
}
