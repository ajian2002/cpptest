#define MYERROR
#include <my/debug.info.h>

struct msgst
{
    long type;
    char msg[128];
} mymsg;
int main()
{
    
    int len;
    char s[128] = "asaaaa";
    int c = 1;
    //提供键值
    key_t key1 = ftok(".", c);
    //创建或访问这个消息队列
    int qid = msgget(key1, IPC_CREAT | 0644);
    //构造消息队列
    mymsg.type = 2;
    strcpy(mymsg.msg, s);
    //发送
    len = strlen(mymsg.msg);
    if (0 != msgsnd(qid, &mymsg, len, 0))
    {
        perror("msgsnd ");
        exit(-1);
    }
}