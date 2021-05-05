#include <my/debug.info.h>
#define INITPTHREADNUMBER 20






int InitPthreadPool(int number);
int main()
{
    //创建线程池
    InitPthreadPool(INITPTHREADNUMBER);
    
}