#define MYERROR
#include <my/debug.info.h>
#include <pthread.h>
#define CLIENT 1
#define SERVER 2
struct msgst
{
    long type;
    char msg[128];
} mysendmsg, myfrommsg;

void *readServer(void *q)
{
    int qid = *((int *)q);
    int len = sizeof(struct msgst) - 4;
    while (1)
    {
        if (-1 != msgrcv(qid, &myfrommsg, len, SERVER, 0))
        {
            if (myfrommsg.type == SERVER)
                printf("server:%s\n", myfrommsg.msg);
        }
        else
        {
            if (errno == ENOMSG)
            {
                ;
            }
            else
            {
                PRINTEXIT("msgrcv ");
            }
        }
    }
    return NULL;
}
int main()
{

    int len;
    int c = 1;
    len = sizeof(struct msgst) - 4;
    //提供键值
    key_t key1 = ftok(".", c);
    //创建或访问这个消息队列
    int qid = msgget(key1, IPC_CREAT | 0644);
    pthread_t thread;
    pthread_create(&thread, NULL, readServer, (void *)&qid);

    //构造消息队列
    while (1)
    {
        printf("client:\n");
        fgets(mysendmsg.msg, len, stdin);
        if (strncmp(mysendmsg.msg, "exit", 4) == 0)
        {
            exit(0);
        }
        mysendmsg.type = CLIENT;
        mysendmsg.msg[strlen(mysendmsg.msg) - 1] = 0;
        //发送
        if (0 != msgsnd(qid, &mysendmsg, len, 0))
        {
            perror("msgsnd ");
            exit(-1);
        }
    }
}