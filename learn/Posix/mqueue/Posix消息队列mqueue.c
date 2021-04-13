#define MYERROR
#include <my/debug.info.h>
#include <mqueue.h>
int main()
{
    //消息队列描述符
    mqd_t mqdes;
    
    //创建
    mqdes = mq_open("mqd_test", O_RDWR | O_CREAT, 0644, NULL); 
    //打开
    //mqdes = mq_open("mqd_test", O_RDWR );
}
