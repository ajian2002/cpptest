# Posix 三部曲之消息队列

| 头文件   | 创建打开或删除 IPC | 控制 IPC 操作 | IPC 操作   |
| :------- | :----------------- | ------------- | ---------- |
| mqueue.h | mq_open            | mq_getattr    | mq_send    |
|          | mq_close           | mq_setattr    | mq_receive |
|          | mq_unlink          |               | mq_motify  |

![1](https://tu.yegetables.com/images/2021/04/12/Posix-IPC.png)

> Posix 消息队列至少具备随`内核的持续性`(非映射文件实现时)

> 对 Posix 消息队列的读总是`返回最高优先级的最早消息`，对 System V 消息队列的读则可以返回任意指定优先级的消息。

> 当往一个`空队列放置一个消息`时，Posix 消息队列允许`产生一个信号或启动一个线程`， System V 消息队列则不提供类似机制。

队列中的每个消息具有如下属性：

> 一个无符号整数优先级（Posix）或一个长整数类型（System V）；

> 消息的数据部分长度（可以为 0）；

> 数据本身（如果长度大于 0）。

```c
#include <mqueue.h>
```

## 消息队列描述符 mqd_t

```c
mqd_t mqdes;
```

# 打开创建 mq_open

### 打开

`mqd_t mq_open(const char *__name, int __oflag, ...)`

    返回消息队列描述符
    pathname
    oflag------>      O_RDWR等

### 创建

`mqd_t mq_open(const char *name, int oflag, mode_t mode, struct mq_attr *attr);`​

    mode  文件权限
    struct    NULL默认属性  也可指定
    `创建`时才能设置`maxmsg`和`msgsize`属性

### e.g

```c
//创建
mqdes = mq_open("mqd_test", O_RDWR | O_CREAT, 0644, NULL);
//打开
mqdes = mq_open("mqd_test", O_RDWR );
```

### 关闭&&删除 mq_close&&mq_unlink

`int mq_close(mqd_t mqdes);`

`int mq_unlink(const char *name);`

# 获取设置属性 mq_getattr&&mq_setattr

### `mq_getattr`

返回所有这些属性

`int mq_getattr(mqd_t mqdes,struct mq_attr *attr)`

### `mq_setattr`

则设置其中某个属性

`int mq_setattr(mqd_t mqdes,const struct mq_attr *attr,struct mq_attr *oattr)`

> 只能设定`flags`,
> `创建`时才能设置`maxmsg`和`msgsize`

### `mq_attr结构`

含有以下属性

```c
struct mq_attr {

long mq_flags;　 /* message queue flag: 0,O_NONBLOCK */

long mq_maxmsg;　/* max number of messages allowed on queue */

long mq_msgsize; /* max size of a message (in bytes)*/

long mq_curmsgs; /* number of messages currently on queue */

};
```

# 添加&&取出 mq_send&&mq_receive

    int mq_send(mqd_t mqdes,const char *ptr,size_t len,unsigned int prio);

`prio--指定优先级`

    ssize_t mq_receive(mqd_t mqdes,char *ptr,size_t len,unsigned int *priop);

`priop可以存放接收的优先级,也可以NULL不接收`

`返回值接收消息字节数`

# 消息队列通知 mq_notify

```c
int mq_notify(mqd_t mqdes,const struct sigevent *notification);

    返回：若成功则为0，若出错则为−1
    该函数为指定队列建立或删除异步事件通知

    struct sigevent  sigev中
        sigev.sigev_notify =SIGEV_SIGNAL //空变非空,有信号产生
        sigev.sigev_signo= SIGUSER1      //指定发送信号

```

## 注意事项
1. `notification`参数`非空`,`先前为空` ` 得到通知`

2. `notification`参数为`空指针`，当前进程目前被注册,`撤销`

3. 任意时刻`只有一个进程`可以被注册为接收`某个给定队列`的通知。

4. `mq_reveive调用中的阻塞比任何通知的注册都优先`。

5. 被`发送`,注册被`撤销`

## 等待消息并处理(同步信号处理)

> 线程可以通过调用sigwait等待一个或多个信号的出现。

> `int sigwait(const sigset_t *restrict set, int *restrict signop);`

    set参数指定了线程等待的信号集。
    signop指向返回的信号值
    返回：若成功则为0，若出错则为正的Exxx值

1. 先初始化并阻塞某个信号集
```c
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGCHLD);
    sigprocmask(SIG_BLOCK,&set, NULL);
```
2. 注册消息队列通知信号
```c
    struct sigevent  sigev;
    sigev.sigev_notify=SIGEV_SIGNAL;
    sigev.sigev_signo= SIGUSER1;
    mq_notify(mqd,&sigev);
```
3. sigwait阻塞等待信号
```c
    int signo;
    sigwait(&set,&signo);
```
4. 处理信号(并再次注册)
```c
    if(signo==SIG_USER1)
    {
        ;
    }
    mq_notify(mqd,&sigev);
```



