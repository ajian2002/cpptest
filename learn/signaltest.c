
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
#include <pthread.h>
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
    
    //signal(SIGINT,er);//捕捉
    //sigprocmask(SIG_BLOCK, &set, NULL);//屏蔽
    
    int j = 10;
    while (j--)
    {
        printf("%d\n", j);
        sleep(2);
    }
    return 0;
}