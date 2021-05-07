
#define MYERROR
#include <my/debug.info.h>
#define MAXLINE 256
#define PORT 45454
int main(int argc, char **argv)
{
    int so = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in clientaddr;
    clientaddr.sin_family = AF_INET;
    clientaddr.sin_port = htons(PORT);
    clientaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    //inet_pton(AF_INET,"127.0.0.1",&clientaddr.sin_addr);
    bind(so, (struct sockaddr *)&clientaddr, sizeof(clientaddr));

    // if (connect(so, (struct sockaddr *)&clientaddr, sizeof(struct sockaddr)) < 0)
    // {
    //     PRINTEXIT("connect error");
    // }
    int n = 0;
    char buf[100] = {0};
    time_t now;
    while (1)
    {
        time(&now);
        memset(buf, 0, sizeof(char) * 100);
        scanf("%s", buf);
        strcat(buf, ctime(&now));
        buf[strlen(buf)] = '\n';
        buf[strlen(buf)] = '\0';
        printf("send %s to server \n", buf);
        if (sendto(so, buf, strlen(buf), 0, (struct sockaddr *)&clientaddr, sizeof(struct sockaddr)) < 0)
        {
            perror("sendto error");
        }
        }
    close(so);

    return 0;
}
