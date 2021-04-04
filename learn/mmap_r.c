#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#define MYERROR
#include <my/debug.info.h>

#define FILELEN 4096
void ummap(int signal)
{
    if (signal == SIGINT)
    {
        printf("cath SIGINT\n");
        exit(0);
    }
}
int main()
{
    signal(SIGINT, ummap);
    int fd;
wwc:
    fd = open("tsxt", O_RDONLY);
    if (fd == -1)
    {
        sleep(1);
        goto wwc;
    }
    char *p = NULL;

    p = mmap(NULL, FILELEN, PROT_READ, MAP_SHARED, fd, 0); //读映射
    if (p == 0)
        PRINTEXIT("mmap error");
    close(fd);
    while (1)
    {
        if (strlen(p))
        {
            printf("%s\n", p);
        }
        sleep(1);
    }
}