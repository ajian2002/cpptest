#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <linux/limits.h>
#include <unistd.h>

#define DEBUG
#define MYERROR
#include <my/debug.info.h>

#include <readline/readline.h>
#include <readline/history.h>

#define SIGNALMAX 256
#define ARGCMAX 128
//普通
#define NO 1

//输出重定向
#define OUT 2

//输入重定向
#define IN 4

//管道
#define PIP 8

//&后台运行
#define BACKGROUND 16

static char lastpath[PATH_MAX] = {0};
#define ONLYSHOW(x) "\001" #x "\002"
void prin4(char *pathbuf) //    $|#
{
    getcwd(pathbuf, PATH_MAX);
    printf("\e[0;34m"
           "myshell in %s "
           "\e[0m"
           "\n",
           pathbuf);
}

void mygetcmd(char *buf) //获取输入&&tabline补全&&方向键&&历史记录
{

    //readline输入可用左右方向移动
    //以及自动补全
    char *b = readline(ONLYSHOW(\e[0;31m) "$ "ONLYSHOW(\e[0m)); //在非打印字符前后加上　\001 和　\002 解决换行显示错乱问题
    long int len = strlen(b);
    add_history(b); //解决上下键查看历史

    b[len++] = '\n';
    b[len] = '\0';

    //写入本地目录下.myshelllhistory文件
    char ho[PATH_MAX] = {0};
    //    printf("11ho %s   env %s\n", ho,getenv("HOME"));
    strcpy(ho, getenv("HOME"));
    //printf("22%s\n", ho);
    strcat(ho, "/.myshellhistory");
    //printf("%s\n", ho);
    FILE *fp = fopen(ho, "a");
    if (fp == NULL)
    {
        perror("open history failed");
        exit(-1);
    }
    if (fwrite(b, sizeof(char), len + 1, fp) != len + 1)
    {
        perror("fwrite failed");
        exit(-1);
    }
    fclose(fp);

    strcpy(buf, b);
    free(b);
}

int explancmd(char *buf, int *count, char list[ARGCMAX][SIGNALMAX], int *number) //存储输入
{
    int len = strlen(buf);
    int length = 0;
    *count = 0;
    char *p = NULL;
    if ((p = strstr(buf, "&&")) != NULL)
    {
        len = (int)(p - buf);
    }
    for (int i = 0; i < len; i++)
    {
        if (buf[i] == '\n') //找到换行
        {
            if (length != 0) //命令执行
            {
                strncpy(list[*count], &buf[i - length], length);
                *count = *count + 1;
                length = 0;
            }
            break;
        }
        else if (buf[i] == ' ')
        {
            if (length != 0)
            {
                strncpy(list[*count], &buf[i - length], length);
                *count = *count + 1;
                length = 0;
            }
            continue;
        }
        else
        {
            length++; //各参数长度
        }
    }

    if ((p = strstr(buf, "&&")) != NULL)
    {
        *number = 2;
        return (int)(p - buf);
    }
    else
    {
        *number = 1;
        return -1;
    }
}

int findexe(char *cmd) //找程序1 未找到0
{
    DIR *dir;
    int only = 3;
    char *path[] = {"./", "/usr/bin", "/bin", NULL};
    struct dirent *dp;
    if (strncmp(cmd, "./", 2) == 0)
    {
        cmd += 2;
        only = 1;
    }
    int i = 0;
    while (path[i] != NULL && only > i)
    {

        dir = opendir(path[i]);
        if (dir == NULL)
        {
            perror("open dir failed");
            exit(-1);
        }
        dp = readdir(dir);
        while (dp != NULL)
        {
            if (strcmp(cmd, dp->d_name) == 0)
            {
                closedir(dir);
                return 1;
            }
            dp = readdir(dir);
        }
        i++;
        closedir(dir);
    }
    return 0;
}

void docmd(int count, char list[ARGCMAX][SIGNALMAX]) //执行命令
{
    int kind = NO;
    int inc = -1, outc = -1; //重定向定位下标
    int pipc = -1;           //管道定位下标

    //初始化清空
    char outfile[SIGNALMAX] = {0};
    char infile[SIGNALMAX] = {0};
    char pipfile[SIGNALMAX] = {0};
    char next[ARGCMAX][SIGNALMAX];
    memset(next, '\0', sizeof(char) * SIGNALMAX * ARGCMAX);
    char path[SIGNALMAX] = {0};
    ////转换execvp格式
    char *ll[SIGNALMAX];
    for (int i = 0; i < SIGNALMAX; i++)
        ll[i] = NULL;

    int temp;
    if (count < 1) //意外
        return;

    //检测kind
    //clear list
    for (int i = 0; i < count; i++)
    {
        if (strncmp(list[i], "|", 1) == 0) //PIP
        {
            kind |= PIP;
            if (strcmp(list[i], "|") == 0) // | abc
            {
                if (i == count - 1)
                {
                    perror("wrong |");
                    exit(-1);
                }

                ;
            }
            else //|abc
            {
                ;
            }
        }
        if (i == count - 1 && strlen(list[i]) == 1 && strncmp(list[i], "&", 1) == 0) //&
        {
            kind |= BACKGROUND;
            memset(list[i], 0, SIGNALMAX);
        }
        if (strncmp(list[i], "<", 1) == 0 && strlen(list[i]) != 1) //<
        {
            kind |= IN;
            strcpy(infile, &list[i][1]);
            memset(list[i], 0, SIGNALMAX);
        }
        if (strncmp(list[i], ">", 1) == 0 && strlen(list[i]) != 1) //>
        {
            kind |= OUT;
            strcpy(outfile, &list[i][1]);
            memset(list[i], 0, SIGNALMAX);
        }
    }

    for (int i = 0; i < count; i++)
    {
        if (strlen(list[i]))
        ll[i] = (char *)list[i];
        else
            ll[i] = NULL;
    } //内置命令存在判断

    if (findexe(list[0]) == 0) //未找到
    {
        if (strcmp(list[0], "cd") == 0) //cd
        {
            int have = 0;
            strcpy(path, getenv("HOME"));

            if (count == 2)
            {
                if (strcmp(list[1], "-") == 0) //-
                {
                    memset(path, 0, sizeof(path));
                    strcpy(path, lastpath);
                    have = 1;
                }
                if (have != 1) //指定普通目录
                {
                    memset(path, 0, sizeof(path));
                    strcpy(path, list[1]);
                }
            }
            if (strlen(path))
            {
                char llt[PATH_MAX] = {0};
                strcpy(llt, lastpath);
                getcwd(lastpath, PATH_MAX);
                // ll--lastpath(now)--path(next)
                if (chdir(path) != 0) //执行&&异常参数处理
                {
                    strcpy(lastpath, llt);
                }
                else
                {
                    return;
                }
            }
            else
            {
                perror("too many arguments");
                exit(1);
            }
        }
        else if (strcmp(list[0], "history") == 0) //history
        {
            char lla[SIGNALMAX] = "";
            strcat(lla, getenv("HOME"));
            strcat(lla, "/.myshellhistory");

            //无管道   只有count 1/2 不超过3
            //有管道好多好多
            if (kind & PIP)
            {
                ; //放弃
            }
            else if (count <= 2 && !(kind & PIP))
            {
                ll[0] = "cat";
                memset(list[0], 0, SIGNALMAX);
                strcpy(list[0], "cat");
                strcpy(list[1], lla);
                ll[1] = (char *)lla;
                //printf("count %d\n%sa\n%sa\n", count,ll[0],ll[1]);
            }
            else
            {
                printf("can't find cmd");
                return;
            }
        }
    }

    int ifopeninfile = 0, ifopenoutfile = 0;
    //printf("kind %d\n",kind);
    //printf("%s\n%s\n%s\n", ll[0], ll[1], ll[2]);
    int pid = fork();
    if (pid < 0)
    {
        perror("fock failed");
        exit(-1);
    }
    int fd, fdin, fdout;
    if (pid == 0) //child
    {
        if (kind & PIP)
        {
            exit(-2);
            int pid2;
            pid2 = fork();
            int fd2;
            if (pid2 < 0)
            {
                perror("fork failed");
                exit(-1);
            }
            else if (pid2 == 0) //child
            {
                fd2 = open("/tmp/temp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
                dup2(fd2, 1);
                execvp(ll[0], ll);
                exit(0);
            }

            if (waitpid(pid2, NULL, 0) == -1)
                printf("wait for cmd2 error\n");
            fd2 = open("/tmp/temp", O_RDONLY);
            dup2(fd2, 0);
            if (findexe(next[0]) == 0)
            {
                perror("can't find cmd2");
                exit(-1);
            }
            execvp(next[0], ll);
            if (remove("/tmp/temp"))
                printf("remove error");
            exit(0);
        }
        if (kind & IN)
        {
            fdin = open(infile, O_RDONLY);
            if (fdin < 0)
            {
                perror("open failed");
                exit(-1);
            }
            dup2(fdin, 0); //stdin
            ifopeninfile = 1;
        }
        if (kind & OUT)
        {
            fdout = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
            if (fdout < 0)
            {
                perror("open failed");
                exit(-1);
            }
            dup2(fdout, 1); //stdout
            ifopenoutfile = 1;
        
        }
        
            //printf("%s\n%s\n%s\n", ll[0], ll[1], ll[2]);
            execvp(ll[0], ll); //处理ll????
            if (ifopenoutfile)
                close(fdout);
            if (ifopeninfile)
                close(fdin);
            exit(0);
        
    }
    else //father
    {
        //wait
        if (kind & BACKGROUND) //后台执行 父程序直接返回
        {
            printf("child pid:%d\n", pid);
            sleep(1);
            return;
        }
        else
        {
            int status;
            wait(&status);
        }
    }
}

void reexec(int argc, char **argv)
{
    //屏蔽ctrl+c
    signal(SIGINT, SIG_IGN);

    //储存lastpath
    getcwd(lastpath, PATH_MAX);

    char list[ARGCMAX][SIGNALMAX];
    int count = 0;
    char *buf = NULL;
    buf = (char *)malloc(sizeof(char) * SIGNALMAX);
    if (buf == NULL)
    {
        perror("malloc failed");
        exit(-1);
    }
    //print显示路径
    char *pathbuf = (char *)malloc(sizeof(char) * PATH_MAX);
    memset(pathbuf, 0, sizeof(char) * PATH_MAX);

    while (1)
    {
        memset(buf, 0, sizeof(char) * SIGNALMAX);
        memset(list, 0, sizeof(char) * ARGCMAX * SIGNALMAX);

        prin4(pathbuf); //命令提示符
        mygetcmd(buf);  //getch获取buf

        //printf("%s\n", buf);
        char *tts = NULL;

        if ((tts = strchr(buf, '~')) != NULL) //替换~
        {
            char path[PATH_MAX] = {0};
            memset(path, 0, sizeof(PATH_MAX));
            strncpy(path, buf, (int)(tts - buf));
            strcat(path, getenv("HOME"));
            strcat(path, tts + 1);
            strcat(path, "/");
            memset(buf, 0, SIGNALMAX);
            strcpy(buf, path);
        }

        int where = -1;
        int number = 1;

        //判断登出
        if (strcmp(buf, "exit\n") == 0 || strcmp(buf, "logout\n") == 0)
        {
            if (pathbuf)
                free(pathbuf);
            if (buf)
                free(buf);
            exit(EXIT_SUCCESS);
        }

        count = 0;
        where = explancmd(buf, &count, list, &number); //存储cmd
        docmd(count, list);
        while (number != 1) //&&
        {

            //判断登出
            if (strcmp(&buf[where + 2], "exit\n") == 0 || strcmp(&buf[where + 2], "logout\n") == 0)
            {
                if (pathbuf)
                    free(pathbuf);
                if (buf)
                    free(buf);
                exit(EXIT_SUCCESS);
            }

            printf("\n");
            count = 0;

            memset(list, 0, sizeof(char) * ARGCMAX * SIGNALMAX);
            where = explancmd(&buf[where + 2], &count, list, &number);
            where = -1;
            docmd(count, list);
        }

        printf("\n");
    }

    if (buf)
        free(buf);
}

int main(int argc, char **argv)
{
    reexec(argc, argv);
    return 0;
}

//main -->reexec-->explain&&docmd