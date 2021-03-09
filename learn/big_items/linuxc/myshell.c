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
#define SIGNALMAX 256
#define ARGCMAX 128
//普通
#define NO 0

//输出重定向
#define OUT 1

//输入重定向
#define IN 2

//管道
#define PIP 4

//&后台运行
#define BACKGROUND 8

void prin4(void) //    $|#
{
    printf("myshell$ ");
}

void getcmd(char *buf) //获取输入
{
    char c;
    c = getchar();
    int len = 0;
    while (c != '\n' && len < SIGNALMAX)
    {
        buf[len] = c;
        len++;
        c = getchar();
    }
    if (len >= SIGNALMAX)
    {
        perror(" cmd too long");
        exit(-1);
    }

    buf[len++] = '\n';
    //buf[len]='\0';
}

void explancmd(char *buf, int *count, char list[ARGCMAX][SIGNALMAX]) //解析输入
{
    int len = strlen(buf);
    int number = 0;
    *count = 0;
    for (int i = 0; i < len; i++)
    {
        if (buf[i] == '\n')
        {
            if (number != 0)
            {
                strncpy(list[*count], &buf[i - number], number);
                *count = *count + 1;
                number = 0;
            }
            break;
        }
        else if (buf[i] == ' ')
        {
            if (number != 0)
            {
                strncpy(list[*count], &buf[i - number], number);
                *count = *count + 1;
                number = 0;
            }
            continue;
        }
        else
        {
            number++;
        }
    }
}

int findexe(char *cmd) //找程序
{
    DIR *dir;
    char *path[] = {"./", "/usr/bin", "/bin", NULL};
    struct dirent *dp;
    if (strncmp(cmd, "./", 2) == 0)
    {
        cmd += 2;
    }
    int i = 0;
    while (path[i] != NULL)
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
    ;
    int kind = NO;
    int inc = -1, outc = -1; //重定向定位下标
    int pipc = -1;           //管道定位下标
    char outfile[SIGNALMAX];
    char infile[SIGNALMAX];
    char pipfile[SIGNALMAX];
    char next[ARGCMAX][SIGNALMAX];
    char path[SIGNALMAX];
    //execvp格式
    char *ll[SIGNALMAX];
    for (int i = 0; i < count; i++)
    {
        ll[i] = (char *)list[i];
    }

    int temp;
    memset(infile, '\0', sizeof(char) * SIGNALMAX);
    memset(outfile, '\0', sizeof(char) * SIGNALMAX);
    memset(pipfile, '\0', sizeof(char) * SIGNALMAX);
    memset(next, '\0', sizeof(char) * SIGNALMAX * ARGCMAX);
    memset(path, '\0', sizeof(char) * SIGNALMAX);
    if (count < 1)
        return;
    int have = 0;
    //命令存在判断
    if (findexe(list[0]) == 0)
    {
        if (strcmp(list[0], "cd") == 0) //cd
        {
            strcpy(path, getenv("HOME"));
            if (count == 2)
            {
                for (int i = 0; i < strlen(ll[1]); i++)
                {
                    if (list[1][i] == '~')
                    {
                        memset(path, 0, sizeof(path));
                        strncpy(path, &list[1][0], i);
                        // puts(path);
                        strcat(path, getenv("HOME"));
                        //puts(path);
                        //strcat(path,"/");
                        strcat(path, &list[1][i + 1]);
                        // puts(path);
                        strcat(path, "/");
                        have = 1;
                    }
                }
                if (have != 1)
                {
                    memset(path, 0, sizeof(path));
                    strcpy(path, ll[1]);
                }
            }
            else if (count == 1)
            {
                chdir(getenv("HOME"));
            }

            if (strlen(path))
            {
                chdir(path);
            }
            else
            {
                perror("too many arguments");
                exit(1);
            }
        }
        else
        {
            perror("can't find cmd");
            return;
        }
    }

    //判断后台运行符&
    for (int i = 0; i < count - 1; i++)
    {
        if (strcmp(list[count - 1], "&") == 0)
        {
            perror("& error ");
            exit(-1);
        }
    }
    if (strcmp(list[count - 1], "&") == 0)
    {
        kind |= BACKGROUND;
        count--;
        memset(list[count], '\0', 1);
    }

    //重定向格式检测      &&pip  各一次
    if (1)
    {
        if (strcmp(list[count - 1], "<") == 0)
        {
            perror("< 位置错误");
            exit(-1);
        }
        if (strcmp(list[count - 1], ">") == 0)
        {
            perror("> 位置错误");
            exit(-1);
        }
        if (strcmp(list[count - 1], "|") == 0)
        {
            perror("| 位置错误");
            exit(-1);
        }
    }
    for (int i = 0; i < count; i++)
    {
        if (list[i][0] == '|')
        {
            kind |= PIP;
            if (pipc == -1)
                pipc = i;
            else
            {
                perror("|次数太多");
                exit(-1);
            }
        }
        if (list[i][0] == '>')
        {
            kind |= OUT;
            if (outc == -1)
                outc = i;
            else
            {
                perror(">重定向次数太多");
                exit(-1);
            }
        }
        if (list[i][0] == '<')
        {
            kind |= IN;
            if (inc == -1)
                inc = i;
            else
            {
                perror("<重定向次数太多");
                exit(-1);
            }
        }
    }
    //if (kind ^ 3 == 3){        perror("不支持同时重定向输入输出");exit(0);}

    //重定向位置设置并清除原位置   &&pip
    if (kind & IN && inc != -1)
    {
        if (list[inc][1] == '\0')
        {
            strcpy(infile, list[inc + 1]);
            memset(list[inc], '\0', SIGNALMAX);
            memset(list[inc + 1], '\0', SIGNALMAX);
        }
        else
        {
            strcpy(infile, list[inc]);
            temp = strlen(infile);
            memmove(infile, &infile[1], temp - 1);
            infile[temp - 1] = '\0';
            memset(list[inc], '\0', SIGNALMAX);
        }
    }
    if (kind & OUT && outc != -1)
    {
        if (list[outc][1] == '\0')
        {
            strcpy(outfile, list[outc + 1]);
            memset(list[outc], '\0', SIGNALMAX);
            memset(list[outc + 1], '\0', SIGNALMAX);
        }
        else
        {
            strcpy(outfile, list[outc]);
            temp = strlen(outfile);
            memmove(outfile, &outfile[1], temp - 1);
            outfile[temp - 1] = '\0';
            memset(list[outc], '\0', SIGNALMAX);
        }
    }

    if (kind & PIP && pipc != -1) //pip
    {
        if (list[pipc][1] == '\0')
        {
            strcpy(pipfile, list[pipc + 1]);
            memset(list[pipc], '\0', SIGNALMAX);
            memset(list[pipc + 1], '\0', SIGNALMAX);
            pipc += 2;
        }
        else
        {
            strcpy(pipfile, list[pipc]);
            temp = strlen(pipfile);
            memmove(pipfile, &pipfile[1], temp - 1);
            pipfile[temp - 1] = '\0';
            memset(list[pipc], '\0', SIGNALMAX);
            pipc += 1;
        }

        strcpy(next[0], pipfile);
        int j = 1;
        for (int i = pipc; i < count; i++)
        {
            if (strlen(list[i]))
                strcpy(next[j++], list[i]);
        }
    }

    //pip与重定向不能共存    目前无法实现
    /*if ()
    {
        ;
    }
    else
    {
        exit(0);
    }*/

    int pid = fork();
    if (pid < 0)
    {
        perror("fock failed");
        exit(-1);
    }

    int fd;

    switch (kind)
    {
    case PIP:
        if (pid == 0)
        {
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
                execvp(list[0], ll);
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
        break;
    case IN:
        if (pid == 0)
        {
            fd = open(infile, O_RDONLY);
            dup2(fd, 0);
            execvp(list[0], ll);

            exit(0);
        }
        break;
    case OUT:
        if (pid == 0)
        {
            fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
            dup2(fd, 1);
            execvp(list[0], ll);
            exit(0);
        }
        break;
    case NO:
        if (pid == 0)
        {
            //printf("\n");
            execvp(list[0], ll);
            exit(0);
        }
        break;
    default:
        break;
    }

    //wait
    if (kind & BACKGROUND) //后台执行 父程序直接返回
    {
        printf("child pid:%d\n", pid);
        return;
    }
    else
    {
        if (waitpid(pid, NULL, 0) == -1)
        {
            perror("wait for child error");
            exit(-1);
        }
    }
}

int main(int argc, char **argv, char **environ)
{
    //屏蔽ctrl+c
    signal(SIGINT, SIG_IGN);

    char list[ARGCMAX][SIGNALMAX];
    int count = 0;

    char *buf = NULL;
    buf = (char *)malloc(sizeof(char) * SIGNALMAX);
    if (buf == NULL)
    {
        perror("malloc failed");
        exit(-1);
    }

    while (1)
    {
        memset(buf, 0, sizeof(char) * SIGNALMAX);

        prin4(); //命令提示符

        getcmd(buf); //getch获取cmd

        //判断登出
        if (strcmp(buf, "exit\n") == 0 || strcmp(buf, "logout\n") == 0)
            break;

        memset(list, '\0', sizeof(char) * SIGNALMAX * ARGCMAX);
        count = 0;
        explancmd(buf, &count, list); //解析cmd

        docmd(count, list);
        //printf("father over\n");
    }

    if (buf)
        free(buf);

    return 0;
}