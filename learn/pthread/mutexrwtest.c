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
#include <pthread.h>
//#include <pthread_mytex_t.h>
#define MYERROR
#include <my/debug.info.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; //初始化互斥量
int i = 0;
void *twothread(void *arg)
{
    int *mmoney = (int *)arg;
    do
    {
        pthread_mutex_lock(&lock); //加锁
        // printf("    %d\n", i++);
        *mmoney -= 10;

        pthread_mutex_unlock(&lock); //解锁
    } while (0);
    //pthread_exit(NULL);
    return NULL;
}
int main()
{
    pthread_t pth;
    int j = 0;
    int money = 300;
    pthread_mutex_init(&lock, NULL); //创建锁
    pthread_attr_getdetachstate();
    // pthread_cancel()
    pthread_create(&pth, NULL, (void *)twothread, (void *)&money);

    while (j++ < 5)
    {
        pthread_mutex_lock(&lock);
        money += 1;
        printf("%d    \n", money);
        pthread_mutex_unlock(&lock);
    }

    // sleep(1);
    printf("before %d    \n", money);
    pthread_join(pth, NULL);
    printf("join after%d    \n", money);
    pthread_mutex_destroy(&lock);
}