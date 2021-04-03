#define MYERROR
#include <my/debug.info.h>
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
//#define __USE_POSIX
#include <signal.h>
#include <sys/time.h>

//alarm();
//setitimer
void er(void)
{
    printf("hello\n");
}
int main(int argc, char **argv)
{
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigprocmask(SIG_BLOCK, &set, NULL);
    int j = 10;
    while (j--)
    {
        printf("%d", j);
        sleep(2);
    }
}