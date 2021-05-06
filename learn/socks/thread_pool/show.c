#define PRINTEXIT
#include "mypool.h"

//my task struct

int main()
{

    //create
    ThreadPool *pool1 = pool_create(3, 100, 100);

    //add queue
    char str[20];
    for (int i = 0; i < 20; i++)
    {
        str[i] = i - '0';
        add_task(pool1, process, (void *)&str[i]);
    }

    pool_destroy(pool1);
    //destory
}