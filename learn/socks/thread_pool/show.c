#define DEBUGPRINT
#include "mypool.h"

//my task struct


/*
----------------------------------------------------------------
gcc mypool.c show.c -lpthread -g  -fsanitize=address -fno-omit-frame-pointer  -Wall && ./a.out
*/
int main()
{

    //create
    ThreadPool *pool1 = pool_create(3, 100, 100);

    sleep(5);
    //add queue
    int str[20];
    for (int i = 0; i < 20; i++)
    {
        str[i] = i ;
        add_task(pool1, process, (void *)&str[i]);
    }

    DEBUGPRINT("task add finish\n");
    sleep(10);
    pool_destroy(pool1);
    //destory

}