#define MYERROR
#include <my/debug.info.h>
//setitimer
void er(void)
{
    while(1)
    printf("hello\n");
}
int main(int argc, char **argv)
{
    alarm(3);

    int i;
    // alarm(1);
    // for (i = 0;; i++)
    // {
    //     printf("%d\n", i);
    // }
    // struct itimerval it, oldit;
    // //初次定时时长
    // it.it_value.tv_sec = 3;
    // it.it_value.tv_usec = 0;
    // //之后每次定时
    // it.it_interval.tv_sec = 5;
    // it.it_interval.tv_usec = 0;

    signal(SIGINT, er);
    // if (setitimer(ITIMER_REAL, &it, &oldit) == -1)
    //     PRINTEXIT("set error");
    while (1)
    {

        printf("1\n");
        sleep(1);
    }
}