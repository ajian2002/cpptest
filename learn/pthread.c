#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void thread(void)
{
    printf("new thread id %d\n",pthread_self());
}
int main()
{
    printf("1");
    pthread_t thread;
    printf("main thread id %d\n",pthread_self());
    if(pthread_create(&thread,NULL,thread,NULL)!=0)
    {
        perror("pthread_create failed!");exit(-1);
    }
    sleep(1);
    exit(0);
}