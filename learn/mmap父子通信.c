//#define __USE_MISC
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <wait.h>
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
int main() //读写文件
{
    char *p = NULL;

    p = mmap(NULL, FILELEN, PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANONYMOUS, -1, 0); //读映射
    if (p == 0)
        PRINTEXIT("mmap error");
    //匿名映射不用手动操作文件
    int len = 0;
    pid_t pid = fork();
    if (pid < 0)
    {
        PRINTEXIT("fork error");
    }
    else if (pid > 0) //父写
    {
        memset(p, 0, FILELEN);
        strcpy(p, "hello,i'm write process.my  pid is ");
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
    else if (pid == 0) // 子读
    {
        signal(SIGINT, ummap);
        while (1)
        {
            if (strlen(p))
            {
                printf("%s\n", p);
            }
            sleep(1);
        }
    }
}