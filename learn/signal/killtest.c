#define MYERROR
#include <my/debug.info.h>
#include <signal.h>
#define PIDMAX 4
int main()
{
    int i = 0;
    pid_t pid[PIDMAX + 1] = {0};
    pid[PIDMAX] = getpid();
    printf("father id %d\n", pid[PIDMAX]);
    for (i; i < PIDMAX; i++)
    {
        pid[i] = fork();
        if (pid[i] == -1)
            PRINTEXIT("fork");
        if (pid[i] == 0)
            break;
        printf("%d id %d\n", i, pid[i]);
    }
    if (i == 4)
    {
        int re = kill(pid[PIDMAX - 1], SIGKILL);
        printf("re=%d\n", re);
        if (re == 0)
            printf("i%d  pid%d killed", i, PIDMAX - 1);
        if (re != 0)
            PRINTEXIT("kill failed")

        // wait(NULL);
        // wait(NULL);
        // wait(NULL);
        
    }
    else
    {
        printf("%d is runnung\n", i);
        sleep(5);
        exit(0);
    }
    wait(NULL);
    wait(NULL);
    wait(NULL);
    printf("child over");
    exit(0);
}