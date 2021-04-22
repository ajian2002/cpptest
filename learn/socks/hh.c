
#define MYERROR
#include <my/debug.info.h>

#define MAXLINE 256
int main(int argc, char **argv)
{
    struct sockaddr_in clientaddr;

    clientaddr.sin_family = AF_INET;
    clientaddr.sin_port = htons(45454);
    //int address;
    // addr.sin_addr.s_addr = inet_pton(AF_INET, argv[1], (void *)&address);
    //inet_pton(AF_INET, argv[1], (void *)&address);
    //addr.sin_addr.s_addr =address;
    clientaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int so = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(so, (struct sockaddr *)&clientaddr, sizeof(struct sockaddr)) < 0)
    {
        PRINTEXIT("connect error");
    }
    int n = 0;
    char buf[100] = {0};
    time_t now;
    while (1)
    {
        time(&now);
        memset(buf, 0, sizeof(char) * 100);
        strcpy(buf, ctime(&now));
        buf[strlen(buf)] = '\n';
        buf[strlen(buf)] = '\0';
        if (strlen(buf) != write(so, buf, strlen(buf)))
            PRINTEXIT("writ error");
        sleep(1);
    }
    close(so);

    return 0;
}
