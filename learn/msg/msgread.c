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
    // char s[128] = "asaaaa";
    int c = 1;
    key_t key1 = ftok(".", c);                //提供键值
    int qid = msgget(key1, IPC_CREAT | 0644); //创建或访问这个消息队列
    //                                             //写消息队列

    // mymsg.type = 1;
    // strcpy(mymsg.msg, s);
    // len = strlen(mymsg.msg);
    // if (0 != msgsnd(qid, &mymsg, len, 0))
    // {
    //     perror("msgsnd ");
    //     exit(-1);
    // }
    len = sizeof(struct msgst) - 4;
    msgrcv(qid, &mymsg, len, 2 , 0);
    printf("%s\n", mymsg.msg);
    msgctl(qid, IPC_RMID, NULL);

}