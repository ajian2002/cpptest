# 思路

### 主程序 main()函数

```
1.主程序执行 creat_daemon()函数创建守护进程,成功返回 0,失败返回-1

2.主程序检查返回值并执行后台任务
```

### 子程序 creat_daemon()创建守护进程函数

```
1.创建子进程，父进程退出(退出终端,前台)

2.创建新会话,使子进程完全独立出来，脱离控制,成为新会话组长

3.再次创建子进程(第二次保证进程不是进程组长),使无法打开终端

4.切换到根目录,防止磁盘挂载占用

5.重设文件权限掩码

6.关闭文件描述符

7.信号处理,如果对于信号处理通过怕生成子进程执行,要设置信号忽略 SIGCHLD 信号,可以避免子进程成为僵尸

8.其他,可以处理别的,也可以返回主程序,执行任务,此时主程序成为守护进程
```
# 代码
```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/param.h>
#include <syslog.h>
int creat_daemon(void)
{
    //1.创建子进程，父进程退出
    pid_t pid = fork();
    if (pid == 0)
    {
        //2.创建新会话,使子进程完全独立出来，脱离控制
        pid = setsid();

        //3.再次创建子进程(第二次保证进程不是进程组长),使终端无法打开
        pid = fork();
        if (pid == 0)
        {
            ;
        }
        else if (pid == -1)
        {
            perror("fork");
            return -1;
        }
        else
        {
            exit(0);
        }
    }
    else if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else
    {
        exit(0);
    }

    //4.切换目录
    chdir("/");

    //5.重设文件权限掩码
    umask(0);

    //6.关文件
    for (int i = 0; i < NOFILE; close(i++))
        ;

    //7.信号处理
    //如果对于信号处理通过怕生成子进程执行,要设置信号忽略SIGCHLD信号,可以避免子进程成为僵尸
    signal(SIGCHLD, SIG_IGN);

    //8.其他,可以处理别的
    //也可以返回主程序,执行任务,此时主程序成为守护进程
    return 0;
}
int main()
{
    if (0 == creat_daemon())//检查返回值
    {
        //do something
        printf("1");
    }
    return 0;
}
```
