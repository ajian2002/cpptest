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
int main()
{
    int fd;
    char *p = NULL, *q = NULL;
    fd = open("cin.in", O_RDWR|O_TRUNC);
    if (fd == -1)
        PRINTEXIT("open");

    // lseek(fd, 20, SEEK_END);
    // write(fd, '\0', 1);
    ftruncate(fd, 20); //存20个有效字符
    int len = lseek(fd, 0, SEEK_END);
    //lseek(fd, 0, SEEK_SET);

    p = (char *)mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARE , fd, 0);
    if (p == MAP_FAILED)
        PRINTEXIT("mmap failed");

    close(fd);
    q = p;

    printf("lenq=%ld,q=%s,q[1]=%d\n", strlen(q), q, *(q + 1) == '\n'); //换行键

    strcat(p, "123456789123456789123456789"); //27

    printf("%s", p); //20

    len = munmap(p, len);
    if (len == -1)
        PRINTEXIT("munmap");
    return 0;
}