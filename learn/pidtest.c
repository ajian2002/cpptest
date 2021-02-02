#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <time.h>
#include <syslog.h>

#include <sys/wait.h>
int m = 0;

int init_daemon(void)
{
    int pid;
    int i;
    //守护进程
    //忽略终端I/O信号 STOP信号
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    signal(SIGHUP, SIG_IGN);
    pid = fork();
    if (pid > 0)
    {
        exit(0); //结束父进程1
    }
    if (pid < 0)
        return -1;

    setsid();     //新建进程组2
    pid = fork(); //再次新建子进程3
    if (pid > 0)
    {
        exit(0); //退出次父进程2
    }
    if (pid < 0)
        return -1;
    //关闭文件描述符
    for (int i = 0; i < NOFILE; close(i++))
        ;
    chdir("/");               //不与文件系统联系
    umask(0);                 //文件屏蔽字
    signal(SIGCHLD, SIG_IGN); //忽略SIGCHLD信号
    return 0;
}
int main(int argc, char **argv, char **environ)
{
    pid_t pid;
    int k = 0;
    char *msg = NULL;
    pid = fork();
    /* 父子进程顺序
    switch (pid)
    {
    case 0:
        printf(" child:%d->%d->%d\n", getppid(), getpid(), pid);
        msg = "child\n";
        k = 3;
        break;
    case -1:
        printf("fork failed\n");
        break;
    default:
        printf(" father: %d->%d->%d\n", getppid(), getpid(), pid);
        msg = "father\n";
        k = 5;
        break;
    }
    while (k)
    {
        puts(msg);
        k--;
        sleep(1);
    }*/
    /*孤儿
    switch (pid)
    {
    case 0:
        while (1)
        {
            printf(" child:%d->%d->%d\n", getppid(), getpid(), pid);
            sleep(1);
        }
        break;
    case -1:
        printf("fork failed\n");
        break;
    default:
        printf(" father: %d->%d->%d\n", getppid(), getpid(), pid);
        break;
    }*/

    //子进程结束输入坑
    switch (pid)
    {
    case 0:
        while (k <= 3)
        {
            k++;
            printf(" child:%d->%d->%d\n", getppid(), getpid(), pid);
            sleep(1);
        }
        break;
    case -1:
        printf("fork failed\n");
        break;
    default:
        printf(" father: %d->%d->%d\n", getppid(), getpid(), pid);
        break;
    }
    if (pid > 0)
    {
        if (waitpid(pid, NULL, 0) == -1)
        {
            perror("wait for child error");
            exit(-1);
        }
    }

    /*全局变量共享 局部变量不共享    vfork共享 fork复制
    switch (pid)
    {
    case 0:

        k += 1;
        m += 1;
        printf(" child:%d->%d->%d\n", getppid(), getpid(), pid);
        printf("%p  k:%d\n", &k, k);
        printf("%p  m:%d\n", &m, m);
        exit(1);
        break;
    case -1:
        printf("fork failed\n");
        break;
    default:
        sleep(3);
        m += 100;
        k += 100;
        printf(" father:%d->%d->%d\n", getppid(), getpid(), pid);
        printf("%p  k:%d\n", &k, k);
        printf("%p  m:%d\n", &m, m);
        break;
    }*/

    /*守护进程
    time_t now;
    init_daemon();
    openlog("test.log", LOG_CONS | LOG_PID, LOG_LOCAL2);
    syslog(LOG_USER| LOG_INFO, "守护进程\n");
    while (k <=20)
    {
        k++;
        sleep(2);
        //time(&now);
        //syslog(LOG_LOCAL2|LOG_INFO, "系统时间\t%s\t\t\n", ctime(&now));
        syslog(LOG_LOCAL2 | LOG_INFO, "%d\n", k);
    }
    closelog();
*/
    //wait和execve
    /*
    printf("%s\n", environ[0]);pid_t pidd=0;
    pid = fork();
    switch (pid)
    {
    case 0:
        sleep(10);
        execve("/home/ajian/code/cpptest/learn/hello", argv, environ);
        exit(1);
        break;
    default:
        //wait(NULL);
        //waitpid(pid, NULL, WNOHANG) ;
        while (k < 10)
        {
            printf("%d", k);
            k++;
            pidd=waitpid(pid, (int *)0, WNOHANG);
            if (pidd <=0)
            {
                printf("%d\n", pidd);
                sleep(3);
            }
            else
            {
                exit(1);
            }
        }

        printf("kill father\n");
        exit(0);
        break;
    }
*/

    return 0;
}
