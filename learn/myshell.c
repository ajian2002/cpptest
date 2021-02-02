#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <linux/limits.h>
#define NO 0
#define OUT 1
#define IN 2
#define PIP 4
void prin4(void) //    $|#
{
    printf("myshell$ ");
}

void getcmd(char *buf) //获取输入
{
    char c;
    c = getchar();
    int len = 0;
    while (c != '\n' && len < 256)
    {
        buf[len] = c;
        len++;
        c = getchar();
    }
    if (len == 256)
    {
        perror(" cmd too long");
        exit(-1);
    }

    buf[len++] = '\n';
    //buf[len]='\0';
}

void explancmd(char *buf, int *count, char list[100][256]) //解析输入
{
    ;
    int len = strlen(buf);
    int number = 0;
    for (int i = 0; i < len; i++)
    {

        if (buf[i] == '\n')
            break;
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
    char *path[] = {"./", "/usr/bin/", "/bin/", NULL};
    struct dirent *d;
    if (strncmp(cmd, './', 2) == 0)
    {
        cmd += 2;
    }
    int i = 0;
    while (path[i] != NULL)
    {
        dp = opendir(path[i]);
        if (dp == NULL)
        {
            perror("open dir failed");
            exit(-1);
        }
        d = readdir(dp);
        while (d != NULL)
        {
            if (strcmp(cmd, d->d_name) == 0)
            {
                close(d);
                return 1;
            }
            d = readdir(d);
        }
        i++;
        closedir(dp);
    }
    return 0;
}

void docmd(int count, char list[100][256]) //执行命令
{
    ;




}



int main(int argc, char **argv, char **environ)
{
    char *buf;
    char list[100][256];
    int count = 0;
    buf = (char *)malloc(sizeof(char) * 256);
    if (buf == NULL)
    {
        perror("malloc failed");
        exit(-1);
    }
    while (1)
    {
        memset(buf, '\0', sizeof(char) * 256);
        prin4();
        getcmd(buf);
        //exit logout
        if (strcmp(buf, "exit\n") == 0 || strcmp(buf, "logout\n") == 0)
        {
            exit(0);
        }

        memset(list, '\0', sizeof(char) * 256 * 100);
        count = 0;
        explancmd(buf, &count, list);
        docmd(count, list);
    }
    if(buf!=NULL)
    free(buf);
    exit(0);
}