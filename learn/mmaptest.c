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
int main()
{
    int fd;
    char *p = NULL, *q = NULL;
    fd = open("cin.in", O_RDWR | O_CREAT, 0777);
    //O_TRUNC 存在则截断
    if (fd == -1)
        PRINTEXIT("open");

    // lseek(fd, 20, SEEK_END);
    // write(fd, '\0', 1);
    ftruncate(fd, 500); //存20个有效字符
    int len = lseek(fd, 0, SEEK_END);
    //lseek(fd, 0, SEEK_SET);

    p = (char *)mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED)
        PRINTEXIT("mmap failed");

    close(fd);
    q = p;

    printf("lenq=%ld,q=%s,q[1]=%d\n", strlen(q), q, *(q + 1) == '\n'); //换行键
    sleep(10);
    strcat(p, "123456789123456789123456789"); //27
    sleep(10);
    printf("%s", p); //20

    len = munmap(p, len);//写回磁盘
    if (len == -1)
        PRINTEXIT("munmap");
    return 0;
}