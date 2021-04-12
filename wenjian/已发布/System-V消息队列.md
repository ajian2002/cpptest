# System V消息队列

## 写

```c
#include <sys/msg.h>
#include <sys/ipc.h>
#include<sys/types.h>
```

### 自定义消息结构体

```c
struct msgst //任意起名
{
    long type; //必须有
    char msg[128]; //任意类型
} mymsg;  //创建对象,,也可以后面自己随时创建对象
```

###  ftok得到键值

```c
//key_t ftok(const char *__pathname, int __proj_id)
      //提供键值
    int c=0; //范围1-255
    key_t key = ftok(".", c);
```

### 创建/访问消息队列

```c
//int msgget(key_t __key, int __msgflg)
//msgflg:
//	IPC_CREAT :无则创建,有则返回
//  IPC_EXCl:与creat一起使用,有则出错-1
     //   
     int qid = msgget(key , IPC_CREAT | 0644);
	
```

###  写入消息队列

```c
   //1.构造消息队列
    mymsg.type = 1;
    strcpy(mymsg.msg, "ababc");
	len =strlen(mymsg.msg);//
	//len=sizeof(struct msgst)-4;//减去long
```

### 发送消息队列

```c
int msgsnd(int __msqid, const void *__msgp, size_t __msgsz, int __msgflg)
//                 qid        struct       			 len        flag
//flag
//		0 消息队列满则阻塞
//    	IPC_NOWAIT 满则立即返回
```

## 查看(终端)

```bash
  ipcs
```



## 读

### 得到键值和消息队列号

[ftok得到键值](# ftok得到键值)

[创建/访问消息队列](# 创建/访问消息队列)



###  利用空结构体储存读到的消息

```c
//ssize_t msgrcv(int __msqid, void *__msgp, size_t __msgsz, long __msgtyp, int __msgflg)
//					qid			struct			len				msg.type		flg
//flg	
//	IPC_NOWAIT 无消息立即返回不阻塞
//  IPC_EXCEPT 返回第一个不为msg.type的结构
//  IPC_NOERROR	如果满足条件的消息大于len,则截断,舍弃超出部分

len = sizeof(struct msgst) - 4;
    msgrcv(qid, &mymsg, len, 1, 0);
    printf("%s\n", mymsg.msg);

```



## 设置属性

```c

//int msgctl(int __msqid, int __cmd, struct msqid_ds *__buf)
//					qid		cmd				struct msqid_ds
//cmd:
//	IPC_STAT	 获取消息队列的msqid_ds结构存入指定位置
//	IPC_SET		 设置属性(仅uid,gid,mode,qbytes)
//  IPC_RMID 	 删消息队列

struct msqid_ds temp;
msgctl(msgid,IPC_STAT,&temp);//获取

```





# 客户端服务端通信实例

## 客户端client

```c
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
    
    key_t key1 = ftok(".", c);
    int qid = msgget(key1, IPC_CREAT | 0644);
    
    pthread_t thread;
    pthread_create(&thread, NULL, readServer, (void *)&qid);

   
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
        
        if (0 != msgsnd(qid, &mysendmsg, len, 0))
        {
            perror("msgsnd ");
            exit(-1);
        }
    }
}
```

## 服务端

```c
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
    key_t key1 = ftok(".", c);                
    int qid = msgget(key1, IPC_CREAT | 0644); 
                                              
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
       
        if (0 != msgsnd(qid, &mysendmsg, len, 0))
        {
            perror("msgsnd ");
            exit(-1);
        }
    }
}
```

