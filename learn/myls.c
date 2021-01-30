#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <linux/limits.h>
#include "color.h"
#define MAXCHAR 80
#define LSNONE 0
#define LSA 1
#define LSL 2

//seeerorr
void myerror(const char *error_string, int line)
{
    fprintf(stderr, "line:%d   ", line);
    perror(error_string);
    exit(1);
}

//struct stat
//{
//    __mode_t st_mode;   /* File mode.  */
//__uid_t st_uid;          /* User ID of the file's owner.	*/
//__gid_t st_gid;          /* Group ID of the file's group.*/
//__off_t st_size;         /* Size of file, in bytes.  */
//struct timespec st_atim; /* Time of last access.  */访问
//struct timespec st_mtim; /* Time of last modification.  */修改
//struct timespec st_ctim; /* Time of last status change.  */更改
/*

S_ISDIR(mode) __S_ISTYPE((mode), __S_IFDIR)//目录文件
S_ISCHR(mode) __S_ISTYPE((mode), __S_IFCHR)//字符设备文件
S_ISBLK(mode) __S_ISTYPE((mode), __S_IFBLK)//块设备文件
S_ISREG(mode) __S_ISTYPE((mode), __S_IFREG)//一般文件
S_ISFIFO(mode) __S_ISTYPE((mode), __S_IFIFO)
S_ISLNK(mode) __S_ISTYPE((mode), __S_IFLNK)//符号链接
S_ISSOCK(mode)//是否为socket
*/

//printf("%s", ctime(&f.st_mtim));
//mon jan 25 23:35:09 2021\n\0
//printf("%o",f.st_mode);33279->100 777

int rlen = MAXCHAR; //本行剩余长度
int maxlen;         //最长文件名长度

//快排
void strqsort(char before[][PATH_MAX + 1], int *now, int l, int r)
{
    int j = l, k = r;
    if (l < r)
    {
        int temp = now[l];
        while (l != r)
        {
            while (l < r && strcmp(before[now[r]], before[temp]) >= 0)
                r--;
            //p[l] = p[r];
            now[l] = now[r];
            while (l < r && strcmp(before[now[l]], before[temp]) <= 0)
                l++;
            //p[r] = p[l];
            now[r] = now[l];
        }
        if (r == l)
            now[r] = temp;

        strqsort(before, now, r + 1, k);
        strqsort(before, now, j, r - 1);
    }
}

// 列出一个文件名字
void singlename(char *name, char colorkind)
{

    //判断本行是否足够打印
    if (rlen < maxlen)
    {
        printf("\n");
        rlen = MAXCHAR;
    }

    //彩色打印
    if (colorkind == 'd')
    {
        printf(L_BLUE "%-s"NONE, name);
    }
    else
    {
        printf("%-s", name);
    }

    //空格补齐
    int kong = maxlen - strlen(name);
    for (int i = 0; i < kong; i++)
    {
        printf(" ");
    }
    //留2个空隙
    printf("  ");
    rlen -= (maxlen + 2);
}

// -l打印一行  没有名字
char lenname(struct stat a)
{
    struct passwd *p;
    struct group *g;
    char mtime[32];

    //文件类型
    if (1)
    {
        //文件类型
        if (S_ISDIR(a.st_mode))
        {
            printf("d");
        }
        else if (S_ISREG(a.st_mode))
            printf("-");
        else if (S_ISLNK(a.st_mode))
            printf("l");
        else if (S_ISCHR(a.st_mode))
            printf("c");
        else if (S_ISBLK(a.st_mode))
            printf("b");
        else if (S_ISFIFO(a.st_mode))
            printf("f");
        else if (S_ISSOCK(a.st_mode))
            printf("s");
    }

    //文件所有者权限
    if (a.st_mode & S_IRUSR)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if (a.st_mode & S_IWUSR)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if (a.st_mode & S_IXUSR)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }

    //同组用户权限
    if (a.st_mode & S_IRGRP)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if (a.st_mode & S_IWGRP)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if (a.st_mode & S_IXGRP)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }

    //其他用户权限
    if (a.st_mode & S_IROTH)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if (a.st_mode & S_IWOTH)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if (a.st_mode & S_IXOTH)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }

    printf("  ");

    //link
    printf("%4ld  ", a.st_nlink);

    //uid gid
    p = getpwuid(a.st_uid);
    g = getgrgid(a.st_gid);
    printf("%-8s ", p->pw_name);
    printf("%-8s ", g->gr_name);

    //size
    printf("%-6ld ", a.st_size);

    //mtime
    strcpy(mtime, ctime(&a.st_mtim)); //mon jan 25 23:35:09 2021\n\0
    mtime[strlen(mtime) - 1] = '\0';
    printf("%s  ", mtime);

    if (S_ISDIR(a.st_mode))
        return 'd';
    else
        return ' ';
}

//对目录处理
void lsdir(int kind, char *path)
{
    DIR *dir;
    struct dirent *p;
    int count = 0;
    char filename[256][PATH_MAX + 1];

    //获得最长文件名
    dir = opendir(path);
    if (dir == NULL)
        myerror("opendir", __LINE__);
    while ((p = readdir(dir)) != NULL)
    {
        if (maxlen < strlen(p->d_name))
        {
            maxlen = strlen(p->d_name);
        }
        count++;
    }
    closedir(dir);
    if (count > 256)
        myerror("two many files", __LINE__);

    //存储文件名 path+name
    dir = opendir(path);
    if (dir == NULL)
        myerror("opendir", __LINE__);
    int lenpath = strlen(path);
    for (int i = 0; i < count; i++)
    {
        p = readdir(dir);
        if (p == NULL)
            myerror("readdir", __LINE__);

        //path+name
        strncpy(filename[i], path, lenpath);
        filename[i][lenpath] = '\0';
        strcat(filename[i], p->d_name);
        filename[i][lenpath + strlen(p->d_name)] = '\0';
    }

    //冒泡排序
    char temp[PATH_MAX + 1];
    /*
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - j; j++)
        {
            if (strcmp(filename[i], filename[j]) > 0)
            {
                memset(temp, '\0', sizeof(temp));
                strcpy(temp, filename[i]);

                memset(filename[i], '\0', strlen(filename[i]));
                strcpy(filename[i], filename[j]);

                memset(filename[j], '\0', strlen(filename[j]));
                strcpy(filename[j], temp);
            }
        }
    }
    //状态转移
    for (int i = 0; i < count; i++)
        lsfile(kind, filename[i]);
*/
    //快速排序

    int teemp[count];
    for (int i = 0; i < count; i++)
        teemp[i] = i;

    strqsort(filename, teemp, 0, count - 1);
    //状态转移
    for (int i = 0; i < count; i++)
        lsfile(kind, filename[teemp[i]]);

    close(dir);
    //没有-l就换行
    if (kind & LSL == 0)
    {
        printf("\n");
    }
}

//对文件处理
void lsfile(int kind, char *name)
{
    //name是所有路径
    //nname是去除隐藏文件的所有路径
    //temp是文件名
    //name-->nname->temp
    char nfilename[PATH_MAX + 1];
    memset(nfilename, '\0', PATH_MAX + 1);
    struct stat st;
    memset(&st, 0, sizeof(struct stat));
    int wei = 0;
    char temp[PATH_MAX];
    memset(temp, '\0', PATH_MAX);

    //找到最后一个/
    wei = 0;
    for (int i = 0; i < strlen(name); i++)
    {
        if (name[i] == '/')
        {
            wei = i + 1;
        }
    }

    //处理a  name得到nname
    if (kind & LSA)
    {
        strcpy(nfilename, name);
    }
    else
    {
        if (name[wei] != '.')
        {
            strcpy(nfilename, name);
        }
    }
    if (strlen(nfilename) == 0)
    {
        return;
    }

    //得到文件名
    strncpy(temp, &nfilename[wei], strlen(nfilename) - wei);
    temp[strlen(nfilename) - wei] = '\0';

    stat(nfilename, &st);
    char colorkind = ' ';
    //确定显示方式  l
    if (kind & LSL)
    {

        colorkind = lenname(st);
        //彩色打印
        if (colorkind == 'd')
            printf(L_BLUE "%s\n" NONE, temp);
        else
            printf("%s\n", temp);
    }
    else
    {
        if (S_ISDIR(st.st_mode))
        {
            colorkind = 'd';
        }
        //色彩传递,彩色打印
        singlename(temp, colorkind);
    }
}

int main(int argc, char **argv) //ls 0  -al 1  / 2  /home 3
{
    srand((unsigned int)time(NULL));
    char path[PATH_MAX + 1];
    int kind = LSNONE;
    int pathnumber = 0;
    struct stat a;
    int mode[250] = {0};
    char temppath[PATH_MAX];
    //解析kind  -lalal
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            int argvlen = strlen(argv[i]);
            for (int j = 1; j < argvlen; j++)
            {
                if (argv[i][j] == 'l')
                {
                    kind |= LSL;
                }
                else if (argv[i][j] == 'a')
                {
                    kind |= LSA;
                }
                else
                {
                    myerror("不支持的参数", __LINE__);
                }
            }
        }
        else
        {
            pathnumber++;
        }
    }

    //单独ls
    if (argc == 1)
    {
        kind = LSNONE;
        strcpy(path, "./");
        path[2] = '\0';
        lsdir(kind, path);
        return 0;
    }

    //解析路径
    for (int i = 1; i < argc; i++)
    {
        memset(path, 0, sizeof(path));
        memset(&a, 0, sizeof(struct stat));
        memset(temppath, '\0', PATH_MAX);
        if (argv[i][0] != '-') //不支持路径名带'-'
        {
            if (argv[i][0] == '/') //单独目录
            {
                strcpy(path, argv[i]);
                path[strlen(argv[i])] = '\0';
            }
            else
            {
                strcpy(temppath, "./");
                strcat(temppath, argv[i]);
                if (stat(temppath, &a) != -1)
                {
                    strcpy(path, temppath);
                }
            }
        }
        else
            continue;

        printf("%s\n", path);

        if (stat(path, &a) == -1)
            myerror("stat", __LINE__);
        if (S_ISDIR(a.st_mode))
        {
            if (path[strlen(path) - 1] != '/')
            {
                path[strlen(path)] = '/';
                path[strlen(path) + 1] = '\0';
            }
            lsdir(kind, path);
        }
        else
        {
            lsfile(kind, path);
        }
        printf("\n");
        maxlen = 0;
        rlen = MAXCHAR;
    }

    if (pathnumber == 0)
    {
        memset(path, 0, sizeof(path));
        memset(&a, 0, sizeof(struct stat));
        strcpy(path, "./");
        if (stat(path, &a) == -1)
            myerror("stat", __LINE__);
        if (S_ISDIR(a.st_mode))
        {
            if (path[strlen(path) - 1] != '/')
            {
                path[strlen(path)] = '/';
                path[strlen(path) + 1] = '\0';
            }
            lsdir(kind, path);
        }
        else
        {
            lsfile(kind, path);
        }
    }
    return 0;
}