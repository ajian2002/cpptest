#define MYERROR
#include <my/debug.info.h>
#define MAXLINE 256

int main(int argc, char **argv)
{
    struct sockaddr_in severaddr;
    severaddr.sin_family = AF_INET;
    severaddr.sin_port = htons(45454);
    severaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    int so = socket(AF_INET, SOCK_STREAM, 0);

    bind(so, (struct sockaddr *)&severaddr, sizeof(struct sockaddr));
    listen(so, 10);

    int newso;
    struct sockaddr_in clientaddr;
    socklen_t len = sizeof(struct sockaddr_in);
    if ((newso = accept(so, (struct sockaddr *)&clientaddr, &len)) < 0)
    {
        PRINTEXIT("accept error");
    }
    int n = 0;
    char buf[1000];
    while ((n = read(newso, buf, MAXLINE)) > 0)
    {
        buf[n] = 0;
        printf("%s", buf);
        sleep(1);
        memset(buf, 0, sizeof(char) * 1000);
    }
    if (n < 0)
        PRINTEXIT("read < 0");
    close(so);
    close(newso);
    return 0;
}
