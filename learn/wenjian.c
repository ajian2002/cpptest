#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

//显示错误函数
void myerror(const char *error_string, int line)
{
    fprintf(stderr, "line:%d   ", line);
    perror(error_string);
    exit(1);
}

//测试文件锁
int lock_test(int fd, struct flock *lock)
{
    if (lock->l_type == F_RDLCK)
        printf(" rdlck\n");
    else if (lock->l_type == F_WRLCK)
        printf("wrlck\n");
    else if (lock->l_type == F_UNLCK)
        printf("unlck\n");

    if (fcntl(fd, F_GETLK, lock) == 0) //执行成功    若可以设置,type设置为unlock
    {
        if (lock->l_type == F_RDLCK)
            printf(" rdlck\n");
        else if (lock->l_type == F_WRLCK)
            printf("wrlck\n");
        else if (lock->l_type == F_UNLCK)
            printf("unlck\n");

        if (lock->l_type == F_UNLCK) //可设置
        {
            printf("test success\n");
            return 0;
        }
        else //有其他锁
        {
            printf("test can't set lock  ");
            if (lock->l_type == F_RDLCK)
                printf("F_RDLCK  ");
            else if (lock->l_type == F_WRLCK)
                printf("F_WRLCK  ");

            printf("has been set  ");
            printf(" pid=%d\n", lock->l_pid);
            return -2;
        }
    }
    else //执行失败
    {
        printf("test failed,can't get lock\n");
        return -1;
    }
}

//设置文件锁
int lock_set(int fd, struct flock *lock)
{
    int m = 0;
    short int type = lock->l_type;
    if (lock->l_type == F_UNLCK)
    {
        goto wcc;
    }

    if (lock_test(fd, lock) == 0)
    {
        lock->l_type = type;
    wcc:
        if (fcntl(fd, F_SETLK, lock) == 0) //设置成功
        {
            if (lock->l_type == F_RDLCK)
                printf("F_RDLCK  set success");
            else if (lock->l_type == F_WRLCK)
                printf("F_WRLCK  set success");
            else if (lock->l_type == F_UNLCK)
                printf("release lock success");
            printf("   pid:%d\n", getpid());
            return 0;
        }
        else
        {
            printf("set lock failed\n");
            return -1;
        }
    }
    else
    {
        return m;
    }
    return 0;
}

//查看文件打开方式
void seefl(int fd)
{
    int mode, app;
    mode = fcntl(fd, F_GETFL, 0);
    if (mode < 0)
        myerror("fcntl getfl ", __LINE__ - 2);
    app = mode & O_ACCMODE;
    if (app == O_RDONLY)
        printf("readonly");
    if (app == O_RDWR)
        printf("rdwr");
    if (app == O_WRONLY)
        printf("wronly");

    if (mode & O_APPEND)
        printf(",append");
    if (mode & O_NONBLOCK)
        printf(",nonblock");
    if (mode & O_SYNC)
        printf(",sync");
    printf("\n");
}

//设置文件打开方式
void setfl(int fd, int cmd)
{
    if (cmd == O_APPEND || cmd == O_NONBLOCK || cmd == O_ASYNC)
    {
        int app = fcntl(fd, F_SETFL, cmd);
        if (app < 0)
            myerror("fcntl setfl ", __LINE__ - 2);
    }
    else
    {
        printf("setfl failed ,cmd false\n");
        return;
    }
}

int main()
{
    int app;
    char buf[20];
    memset(buf, 0, sizeof(buf));
    struct flock lock;
    //int fc = creat("/home/ajian/code/cpptest/learn/cin", S_IRWXU);
    int fo = open("/home/ajian/code/cpptest/learn/cin.in", O_RDWR); //777  00700 S_IRWXU
    if (fo == -1)
        myerror("open", __LINE__ - 2);

    //seefl(fo);
    // setfl(fo, O_APPEND);
    //seefl(fo);
    //printf("%d  %d\n", O_WRONLY, O_ACCMODE);
    //append   2^10   1024    10000000000
    //rdonly   0      0       00
    //wronly   2^0    1       01
    //rdwr     2^1    2       10
    //accmode         3       11
    memset(&lock, 0, sizeof(struct flock));
    lock.l_start = SEEK_SET;
    lock.l_whence = 0;
    lock.l_len = 0;

    lock.l_type = F_RDLCK;
    lock_set(fo, &lock);

    lseek(fo, 0, SEEK_SET);
    if (read(fo, buf, 10) < 0)
        myerror("read", __LINE__ - 2);
    printf("%s\n", buf);
    getchar();

    lock.l_type = F_WRLCK;
    lock_set(fo, &lock);

    lock.l_type = F_UNLCK;
    lock_set(fo, &lock);
    close(fo);

    /*
    printf("%d,%d\n", fo, fo); //3 4
    char *s = (char *)malloc(sizeof(char) * 10);
    memset(s, '\0', sizeof(char) * 10);
    read(fo, s, 2);
    printf("%s\n", s);
    memcpy(s, "12345678", 9);
    write(fo, s, 7);
    lseek(fo, 0, SEEK_END);
    write(fo, s, 7);
    close(fo);
    free(s);
    //perror("abc");
    //默认有   str: status
    //printf("aa :%s     \n", strerror(errno));
    */
    return 0;
}