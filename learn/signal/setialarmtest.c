#define MYERROR
#include <my/debug.info.h>
//alarm();
//setitimer
void er(void)
{
    printf("hello\n");
}
int main(int argc, char **argv)
{
    int i;
    // alarm(1);
    // for (i = 0;; i++)
    // {
    //     printf("%d\n", i);
    // }
    struct itimerval it, oldit;
    //初次定时时长
    it.it_value.tv_sec = 3;
    it.it_value.tv_usec = 0;
    //之后每次定时
    it.it_interval.tv_sec = 5;
    it.it_interval.tv_usec = 0;

    signal(SIGALRM, er);
    if (setitimer(ITIMER_REAL, &it, &oldit) == -1)
        PRINTEXIT("set error");
    while (1)
        ;
}