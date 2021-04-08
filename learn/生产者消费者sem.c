#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

char header[10] = {0}; //缓冲区大小10
sem_t fre;
sem_t used;
void *producter(void *argv)
{
    char temp[30] = {0};
    do
    {
        sem_wait(&fre);//fre--  为负则堵塞 
        strcpy(temp, "aaa");
        strcat(header, temp);
        sem_post(&used);//used++ 
        memset(temp, 0, sizeof(char) * 30);

        sleep(rand() % 3);
    } while (1);
}

void *customer(void *argv)
{
    do
    {
        sem_wait(&used);//used-- 为负堵塞
        printf("%s\n", header);
        header[strlen(header - 3)] = '\0';
        sem_post(&fre);//fre++
        sleep(rand() % 3);
    } while (1);
}

int main()
{
    pthread_t tid[12];
    srand(time(NULL));

    sem_init(&used, 0, 0);
    sem_init(&fre, 0, 3);//最多生产3个数据
    
    int i = 0;
    for (i = 0; i < 5; i++)
        pthread_create(&tid[i], NULL, customer, NULL);
    for (i = 0; i < 5; i++)
        pthread_create(&tid[i], NULL, producter, NULL);
    sleep(15);

    sem_destroy(&used);
    sem_destroy(&fre);
}