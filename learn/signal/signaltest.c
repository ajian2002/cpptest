
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
#include <signal.h>
#include <sys/time.h>

//alarm();
//setitimer
void er(int number)
{
    if (number == SIGINT)
    {
        printf("hello\n");
        sleep(2);
    }
    return;
}
int main(int argc, char **argv)
{
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    // sigprocmask(SIG_BLOCK, &set, NULL);//屏蔽
    // sigprocmask(SIG_UNBLOCK, &set, NULL)//解除屏蔽

    // signal(SIGINT,er);//捕捉(尽量避免使用)

    //int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);

    struct sigaction new, old;
    new.sa_handler = er;         //执行函数名
    sigemptyset(&new.sa_mask);   //设置屏蔽字
    new.sa_flags = SA_RESTART ; //0 默认操作
    sigaction(SIGINT, &new, &old);
    int j = 10;
    while (j--)
    {
        printf("%d\n", j);
        sleep(2);
    }
}
