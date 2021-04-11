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
void *readClient(void *q)
{
    int qid = *((int *)q);
    int len = sizeof(struct msgst) - 4;

    while (1)
    {
        if (-1 != msgrcv(qid, &myfrommsg, len, CLIENT, 0))
        {
            if (myfrommsg.type == CLIENT)
                printf("client:\n%s\n", myfrommsg.msg);
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
    // char s[128] = "asaaaa";
    int c = 1;
    key_t key1 = ftok(".", c);                //提供键值
    int qid = msgget(key1, IPC_CREAT | 0644); //创建或访问这个消息队列
                                              //写消息队列
    len = sizeof(struct msgst) - 4;
    pthread_t thread;
    pthread_create(&thread, NULL, readClient, (void *)&qid);

    while (1)
    {
        printf("server:\n");
        fgets(mysendmsg.msg, len, stdin);
        if (strncmp(mysendmsg.msg, "exit", 4) == 0)
        {
            exit(0);
        }
        mysendmsg.type = SERVER;
        mysendmsg.msg[strlen(mysendmsg.msg) - 1] = 0;
        // strcpy(mymsg.msg, s);
        //len = strlen(mymsg.msg);
        if (0 != msgsnd(qid, &mysendmsg, len, 0))
        {
            perror("msgsnd ");
            exit(-1);
        }
    }
    //printf("%s\n", mymsg.msg);
    //msgctl(qid, IPC_RMID, NULL);
}