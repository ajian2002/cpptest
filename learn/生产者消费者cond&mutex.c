#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
char header[10] = {0}; //缓冲区大小10
void *producter(void *argv)
{
    //生产者
    //1. 加锁
    //2. 判断缓冲区容量
    //      空闲/充足:
    //          生产+操作+通知
    //3. 解锁

    char temp[30] = {0};
    do
    {
        //满了不生产
        pthread_mutex_lock(&mutex);
        if (strlen(header) != 9) //判断是否满
        {
            printf("i am producter%ld\n", pthread_self());
            strcpy(temp, "aaa");
            strcat(header, temp);
            pthread_cond_signal(&cond);
        }
        pthread_mutex_unlock(&mutex);

        memset(temp, 0, sizeof(char) * 30);

        sleep(rand() % 3);
    } while (1);
}

void *customer(void *argv)
{
    //消费者
    //1.加锁
    //2.判断
    //      缓冲区空:堵塞
    //3.操作
    //4.解锁
    do
    {
        pthread_mutex_lock(&mutex);
        while (strlen(header) == 0) //空了不消费
            pthread_cond_wait(&cond, &mutex);
        printf("               %s\n", header);
        header[strlen(header) - 3] = '\0';
        pthread_mutex_unlock(&mutex);
        printf("                       i am customer %ld\n", pthread_self());
        sleep(rand() % 3);
    } while (1);
}

int main()
{
    pthread_t tid[12];
    srand(time(NULL));
    int i = 0;
    for (i = 0; i < 5; i++)
        pthread_create(&tid[i], NULL, customer, NULL);
    for (i = 0; i < 5; i++)
        pthread_create(&tid[i], NULL, producter, NULL);
    sleep(100);
}