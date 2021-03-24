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
//#define DEBUG
#define MYERROR
//#undef DEBUG
//#include <my/debug.info.h>
#ifdef DEBUG
#define DEBUGPRINT(format, ...) printf("[%s][%s][%d]" format "\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);

#else
#define DEBUGPRINT(format, ...)
#endif

#ifdef MYERROR
#define PRINTEXIT(format, ...)                                                               \
    {                                                                                        \
        printf("[%s][%s][%d]" format "\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
        exit(-1);                                                                            \
    }
#else
#define PRINTEXIT(format, ...)
#endif

#include <readline/readline.h>
#include <readline/history.h>

// [v]实现 内建命令（cd ）
// [v]屏蔽一些信号（如ctrl + c 不能终止）
// [v]通过设置环境变量 可以直接使用 (在任意地方都可以运行你的shell)
// [v]界面美观
// [v]实现光标的移动
// [v]实现内置命令history
// [v]实现 tab补全 （提示:使用readline库）
// [v]实现 输入输出重定向(<> >>)
// [v]实现 后台运行（ &）(ps:linuxc上的&实现其实并]不是真正的后台运行，可以考虑一下为什么)
// [v]实现 管道（也就是 | ）
// [v]实现多重管道（eg：ls -l | grep abc | wc -l）

#define SIGNALMAX 256
#define ARGCMAX 128
//普通
#define NO 1
//输出重定向
#define OUT 2
//输入重定向
#define IN 4
//&后台运行
#define BACKGROUND 8

static char lastpath[PATH_MAX] = {0};
#define ONLYSHOW(x) "\001" #x "\002"

void prin4(char *pathbuf) //$|#
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

    add_history(b); //解决上下键查看历史

    strcat(b, "\n");

    long int len = strlen(b);
    //写入本地目录下.myshelllhistory文件
    char ho[PATH_MAX] = {0};
    //    printf("11ho %s   env %s\n", ho,getenv("HOME"));
    strcpy(ho, getenv("HOME"));
    //printf("22%s\n", ho);
    strcat(ho, "/.myshellhistory");
    //printf("%s\n", ho);
    FILE *fp = fopen(ho, "a");
    if (fp == NULL)
        // {
        //     perror("open history failed");
        //     exit(-1);
        // }
        PRINTEXIT("open history failed");
    if (fwrite(b, sizeof(char), len, fp) != len)
        // {
        //     perror("fwrite failed");
        //     exit(-1);
        // }
        PRINTEXIT("fwrite failed");
    fclose(fp);

    strcpy(buf, b);
    free(b);
}

int explancmd(char *buf, int *count, char list[ARGCMAX][SIGNALMAX], int *number) //存储输入
{

    char *p = NULL;
    char ttsdf[SIGNALMAX] = {0};
    if ((p = strchr(buf, '|')) != NULL)
    {
        strncpy(ttsdf, buf, (int)(p - buf));
        strcat(ttsdf, " >/tmp/.myshellpipfile1 && cp /tmp/.myshellpipfile1 /tmp/.myshellpipfile2 && </tmp/.myshellpipfile2 ");
        strcat(ttsdf, &buf[(int)(p - buf) + 1]);
        memset(buf, 0, SIGNALMAX);
        strcpy(buf, ttsdf);
    }

    int len = strlen(buf);
    int length = 0;
    *count = 0;
    p = NULL;
    if ((p = strstr(buf, "&&")) != NULL)
        len = (int)(p - buf);
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
            length++; //各参数长度
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
            // {
            //     perror("open dir failed");
            //     exit(-1);
            // }
            PRINTEXIT("open dir failed");
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

void docmd(int count, char list[ARGCMAX][SIGNALMAX], int kind) //执行命令
{
    char path[SIGNALMAX] = {0};
    char *ll[SIGNALMAX];
    for (int i = 0; i < SIGNALMAX; i++)
        ll[i] = NULL;

    int temp;
    if (count < 1) //意外
        return;

    //检测kind
    //clear list
    char outfile[ARGCMAX][SIGNALMAX] = {{0}};
    char infile[ARGCMAX][SIGNALMAX] = {{0}};
    int incount = 0, outcount = 0;

    // for (int i = 0; i < count; i++)
    // {
    //     DEBUGPRINT("list[%d]:%s\n", i, list[i]);
    // }
    for (int i = 0; i < count; i++)
    {
        if (i == count - 1 && strlen(list[i]) == 1 && strncmp(list[i], "&", 1) == 0) //&
        {
            kind |= BACKGROUND;
            memset(list[i], 0, SIGNALMAX);
        }
        if (strncmp(list[i], "<", 1) == 0 && strlen(list[i]) != 1) //<
        {
            kind |= IN;
            while (strlen(infile[incount]))
                incount++;

            //处理管道
            strcpy(infile[incount++], &list[i][1]);
            memset(list[i], 0, SIGNALMAX);
        }
        if (strncmp(list[i], ">", 1) == 0 && strlen(list[i]) != 1) //>
        {
            kind |= OUT;
            while (strlen(outfile[outcount]))
                outcount++;

            //处理管道

            strcpy(outfile[outcount++], &list[i][1]);
            memset(list[i], 0, SIGNALMAX);
        }

        /* if (strncmp(list[i], "|", 1) == 0) //PIP
        {
            kind |= PIP;
            char *pipfile = ">p/tmp/.myshellpipfile && </tmp/.myshellpipfile ";
            if (strcmp(list[i], "|") == 0) // | abc
            {
                if (i == count - 1)
                {
                    perror("wrong |");
                    return;
                }

                //修改参数
                memset(list[i], 0, SIGNALMAX);
                strcpy(list[i], pipfile);
            }
            else //|abc
            {
                strcat(pipfile, &list[i][1]);
                memset(list[i], 0, SIGNALMAX);
                strcpy(list[i], pipfile);
            }
            i--;
        }
        */
    }

    //内置命令存在判断
    int iffind = 0;
    for (int i = 0; i < count; i++)
    {
        if (findexe(list[i]) == 0) //未找到
        {
            if (strcmp(list[i], "cd") == 0) //cd
            {
                iffind = 1;
                int common = 0;
                strcpy(path, getenv("HOME"));

                if (count == 2)
                {
                    if (strcmp(list[i + 1], "-") == 0) //-
                    {
                        memset(path, 0, sizeof(path));
                        strcpy(path, lastpath);
                        common = 1;
                    }
                    if (common != 1) //指定普通目录
                    {
                        memset(path, 0, sizeof(path));
                        strcpy(path, list[1 + i]);
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
            else if (strcmp(list[i], "history") == 0) //history
            {
                iffind = 1;
                char lla[SIGNALMAX] = "";
                strcat(lla, getenv("HOME"));
                strcat(lla, "/.myshellhistory");

                //无管道   只有count 1/2 不超过3
                //有管道好多好多
                if (count <= 2)
                {
                    ll[i] = "cat";
                    memset(list[i], 0, SIGNALMAX);
                    strcpy(list[i], "cat");
                    strcpy(list[i + 1], lla);
                    ll[i + 1] = (char *)lla;
                    //printf("count %d\n%sa\n%sa\n", count,ll[0],ll[1]);
                }
                else
                {
                    printf("can't find cmd");
                    return;
                }
            }
        }
        else
            iffind = 1;
    }
    if (iffind == 0)
    {
        perror("can't find cmd");
        return;
    }

    //printf("kind %d\n",kind);
    //printf("%s\n%s\n%s\n", ll[0], ll[1], ll[2]);

    //change ll list

    //int s=1;
    int j = 0;
    for (int i = 0; i < ARGCMAX; i++)
    {
        if (strlen(list[i]))
            ll[j++] = (char *)list[i];
        else
        {
            continue;
        }
    }
    // for (int i = 0; i < count; i++)
    // {
    //     DEBUGPRINT("list[%d]:%s\n", i, list[i]);
    // }
    int pid = fork();
    if (pid < 0)
        // {
        //     perror("fock failed");
        //     exit(-1);
        // }
        PRINTEXIT("fock failed");
    int fd;
    int fdin[incount];
    int fdout[outcount];
    if (pid == 0) //child
    {
        /* if (kind & PIP)
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
        */
        if (kind & IN)
        {
            //   DEBUGPRINT("IN YES\n\n");
            for (int i = 0; i < incount; i++)
            {
                fdin[i] = open(infile[i], O_RDONLY);
                if (fdin[i] < 0)
                    // {
                    //     perror("open failed");
                    //     exit(-1);
                    // }
                    PRINTEXIT("open failed");
                dup2(fdin[i], 0); //stdout
            }
        }
        if (kind & OUT)
        {
            //DEBUGPRINT("OUT YES\n\n");
            for (int i = 0; i < outcount; i++)
            {
                fdout[i] = open(outfile[i], O_RDWR | O_CREAT | O_TRUNC, 0644);
                if (fdout[i] < 0)
                    // {
                    //     perror("open failed");
                    //     exit(-1);
                    // }
                    PRINTEXIT("open failed");
                dup2(fdout[i], 1); //stdout
            }
        }

        //DEBUGPRINT("ll0:%s\nll1:%s\nll2:%s\nkind:%d\n", ll[0], ll[1], ll[2], kind);
        // int ms = 0;
        // while (!strlen(ll[ms]))
        //     ms++;

        //处理数组

        execvp(ll[0], ll);
        //关文件
        if (incount)
        {
            while (incount)
                close(fdin[--incount]);
        }
        if (outcount)
        {
            while (outcount)
                close(fdout[--outcount]);
        }

        exit(0);
    }
    else //father
    {
        //wait
        if (kind & BACKGROUND) //后台执行 父程序直接返回
        {
            printf("child pid:%d\n", pid);
            sleep(3);
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

    char list[ARGCMAX][SIGNALMAX] = {{0}};
    int count = 0;
    char *buf = NULL;
    buf = (char *)realloc(buf, sizeof(char) * SIGNALMAX);
    if (buf == NULL)
        // {
        //     perror("malloc failed");
        //     exit(-1);
        // }
        PRINTEXIT("malloc failed");
    //print显示路径

    char *pathbuf = NULL;
    pathbuf = (char *)realloc(pathbuf, sizeof(char) * PATH_MAX);
    memset(pathbuf, 0, sizeof(char) * PATH_MAX);

    while (1)
    {
        memset(buf, 0, sizeof(char) * SIGNALMAX);
        memset(list, 0, sizeof(char) * ARGCMAX * SIGNALMAX);

        prin4(pathbuf); //命令提示符
        mygetcmd(buf);  //getch获取buf

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

        // for (int i = 0; i < count; i++)
        // {
        //     DEBUGPRINT("list[%d]:%s\n", i, list[i]);
        // }
        docmd(count, list, NO);
        //DEBUGPRINT("number %d where %d\nbuf :%s", number, where, buf);
        memmove(buf, &buf[where + 2], strlen(buf));
        while (number != 1) //&&
        {
            //判断登出
            if (strcmp(buf, "exit\n") == 0 || strcmp(buf, "logout\n") == 0)
            {
                if (pathbuf)
                {
                    free(pathbuf);
                    pathbuf = NULL;
                }
                if (buf)
                {
                    free(buf);
                    buf = NULL;
                }
                exit(EXIT_SUCCESS);
            }

            printf("\n");
            count = 0;
            memset(list, 0, sizeof(char) * ARGCMAX * SIGNALMAX);
            where = explancmd(buf, &count, list, &number);
            // for (int i = 0; i < count; i++)
            // {
            //     DEBUGPRINT("list[%d]:%s\n", i, list[i]);
            // }

            docmd(count, list, NO);

            //DEBUGPRINT("number %d where %d\nbuf :%s", number, where, buf);
            memmove(buf, &buf[where + 2], strlen(buf));
        }
        printf("\n");
    }
    if (pathbuf)
        free(pathbuf);
    if (buf)
        free(buf);
}

int main(int argc, char **argv)
{
    reexec(argc, argv);
    return 0;
}

//main -->reexec-->explain&&docmd