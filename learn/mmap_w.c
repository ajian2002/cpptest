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
// int msync ( void * addr , size_t len, int flags)
//一般说来，进程在映射空间的对共享内容的改变并不直接写回到磁盘文件中，往往在调用munmap（）后才执行该操作。可以通过调用msync() 实现磁盘上文件内容与共享内存区的内容一致。
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
    int fd = open("tsxt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        PRINTEXIT("open error");
    ftruncate(fd, 500);

    char *p = NULL;

    p = mmap(NULL, FILELEN, PROT_WRITE, MAP_SHARED, fd, 0); //写映射
    if (p == NULL)
        PRINTEXIT("mmap error");
    close(fd);
    msync(p, FILELEN, MS_INVALIDATE);
    printf("father0\n");
    memset(p, 0, FILELEN);
    msync(p, FILELEN, MS_INVALIDATE);
    printf("father1\n");
    strcpy(p, "hello,i'm write process.my  pid is ");
    msync(p, FILELEN, MS_INVALIDATE);
    printf("father2\n");

    len = strlen(p);
    int j = 0;
    char ss[FILELEN] = {0};
    sprintf(&ss[strlen(ss)], "%d\n", getpid());
    strcat(p, ss);

    printf("p0=%d\n", p[0]);

    for (; j < 10; j++)
    {
        memset(ss, 0, FILELEN);
        //sprintf(&p[strlen(p)], "%d\n", j);
        sprintf(ss, "%d", j);
        strcat(p, ss);
        sleep(1);
    }
    //printf("%s\n", p);
    wait(NULL);
    len = munmap(p, FILELEN);
    if (len == -1)
    {
        PRINTEXIT("munmap failed");
    }
    return 0;
}