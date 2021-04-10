#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
pthread_key_t key;
int thread(void)
{
    int d = 3;

    pthread_setspecific(key, (void *)d); //一键多值

    printf("new  thread id %lu\n", pthread_self());

    pthread_exit(-3);
}
int main()
{
    //printf("1");
    pthread_t thid;
    printf("main thread id %lu\n", pthread_self());
    pthread_key_create(&key, NULL);
    if (pthread_create(&thid, NULL, (void *)thread, NULL) != 0)
    {
        perror("pthread_create failed!");
        exit(-1);
    }
    int status;
    pthread_join(thid, &status);
    printf(" status is %d\n", status);
    sleep(1);

    exit(0);
}