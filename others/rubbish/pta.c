#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/param.h>
#include <syslog.h>
//System V
#include <sys/msg.h> //消息队列
#include <sys/sem.h> //信号量
#include <sys/shm.h> //共享内存区
//Posix
#include <mqueue.h>    //消息队列
#include <semaphore.h> //信号量
#include <sys/mman.h>  //共享内存区
#include <math.h>
int sushu(int sss)
{
    int i;
    int part = pow(sss, 0.5);
    // printf("%d", part);
    if (sss == 1 || sss == 0)
    {
        return 0;
    }
    else
    {
        for (i = 2; i <= part; i++)
        {
            if (sss % i == 0)
                return 0;
        }

        return 1;
    }
}
int main()
{
    long int m, n;
    m = 0, n = 0;
    scanf("%ld", &n);

    for (int i = 2; i < 1 + pow(n, 0.5); i++)
    {
        if (n / i != i)
            if (n % i == 0 && sushu(i) == 1 && 1 == sushu(n / i))
            {
                printf("%ld = %d + %d\n", n, i, (int)(n / i));
                return 0;
            }
    }
}