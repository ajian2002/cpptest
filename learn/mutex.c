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
//pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
void *twothread(void *)
{
    while (1)
    {
        printf("1");
    }
    pthread_exit(NULL);
    return NULL;
}
int main()
{
    pthread_t pth;

    // pthread_mutex_init(&pth, NULL);
    // pthreead_mutex_lock(&pth, NULL);
    pthread_create(&pth, NULL, twothread, NULL);
    while (1)
    {
        printf("2");
    }
    pthread_join(pth, NULL);
}