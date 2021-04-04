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
int main()
{
    //匿名映射不用手动操作文件

    char *p = NULL;
    int len = 0;
    p = mmap(NULL, FILELEN, PROT_READ, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (p == NULL)
        PRINTEXIT("mmap error");
        
    memset(p, 0, FILELEN);
    strcpy(p, "hello,i'm write process.my  pid is ");
    len = strlen(p);
    int j = 0;
    sprintf(&p[strlen(p)], "%d\n", getpid());
    for (; j < 10; j++)
    {
        sleep(3);
        sprintf(&p[strlen(p)], "%d\n", j);
    }
    len = munmap(p, FILELEN);
    if (len == -1)
    {
        PRINTEXIT("munmap failed");
    }
    return 0;
}