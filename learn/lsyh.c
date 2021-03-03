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
#include "./color.h"
#define MAXFILES 51200
#define MAXCHAR 120
#define LSNONE 0
#define LSA 1
#define LSL 2
#define LSI 4
#define LSR 8
//-a -l 目录蓝色 已支持  //-i  未完成 -R 未完成

//快排  字符串索引排序 已优化
//color.h 在 https://pan.yegetables.com/s/zgul  查看获取
//下载后放置于/usr/include目录下

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
void strqsort(char *before[PATH_MAX], int now[], int l, int r)
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
        printf(L_BLUE "%-s" NONE, name);
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
    strcpy(mtime, ctime(&a.st_mtime)); //mon jan 25 23:35:09 2021\n\0
    mtime[strlen(mtime) - 1] = '\0';
    printf("%s  ", mtime);

    if (S_ISDIR(a.st_mode))
        return 'd';
    else
        return ' ';
}

//解析文件路径并修正
void isrightfile(char *fakepath)
{
    struct stat a;
    memset(&a, 0, sizeof(struct stat));
    //目录补全   正误勘别
    if (lstat(fakepath, &a) == -1)
    {
        printf("%s:\n", fakepath);
        myerror("lstat", __LINE__);
    }
    if (S_ISDIR(a.st_mode))
    {
        if (fakepath[strlen(fakepath) - 1] != '/')
        {
            fakepath[strlen(fakepath)] = '/';
            fakepath[strlen(fakepath) + 1] = '\0';
        }
    }
    //return fakepath;
}
void explainfakepath(char *argv, char *path)
{

    //输入 预期
    //  (1)/a
    //  (2)     ./   ||    .
    //  (3) abc--->(./abc)
    //  (4)  ./abc

    if (argv[0] == '/') //单独目录(1)
    {
        strcpy(path, argv);
    }
    else if (!strcmp(argv, ".") || !strcmp(argv, "./")) //(2)
    {
        strcpy(path, "./");
    }
    else if (!strncmp(argv, "./", 2) && strlen(argv) != 2) //(4)
    {
        strcpy(path, argv);
    }
    else //(3)
    {
        strcpy(path, "./");
        strcat(path, argv);
    }
    isrightfile(path);
}

//对文件处理
void lsfile(int kind, char *name)
{
    //name是所有路径
    //nname是去除隐藏文件的所有路径
    //temp是文件名
    //name-->nname->temp
    char nfilename[PATH_MAX];
    memset(nfilename, 0, PATH_MAX);
    struct stat st;
    memset(&st, 0, sizeof(struct stat));
    int wei = 0;
    char temp[PATH_MAX];
    memset(temp, 0, PATH_MAX);

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

    lstat(nfilename, &st);
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

//对目录处理
void lsdir(int kind, char *path)
{
    //printf("1\n");
    DIR *dir;
    struct dirent *p = NULL;
    int count = 0;

    char*filename[MAXFILES];

    for (int i = 0; i < MAXFILES; i++)
    {
        filename[i] = (char *)malloc(sizeof(char) * PATH_MAX);
        memset(filename[i], 0, PATH_MAX);
    }
    //获得最长文件名
    dir = opendir(path);
    if (dir == NULL)
    {
        for (int i = 0; i < MAXFILES; i++)
            free(filename[i]);
        myerror("opendir", __LINE__);
    }
    while ((p = readdir(dir)) != NULL)
    {
        if (maxlen < strlen(p->d_name))
        {
            maxlen = strlen(p->d_name);
        }

        count++;
    }
    closedir(dir);

    if (count > MAXFILES)
    {
        for (int i = 0; i < MAXFILES; i++)
            free(filename[i]);
        myerror("two many files", __LINE__);
    }
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
        strncpy((filename[i]), path, lenpath);
        filename[i][lenpath] = '\0';
        strcat((filename[i]), p->d_name);
        filename[i][lenpath + strlen(p->d_name)] = '\0';
    }
    closedir(dir);
    int teemp[count];
    for (int i = 0; i < count; i++)
        teemp[i] = i;
    strqsort(filename, teemp, 0, count - 1);

    //状态转移
    for (int i = 0; i < count; i++)
        lsfile(kind, (char *)(filename[teemp[i]]));
    for (int i = 0; i < MAXFILES; i++)
        free(filename[i]);
    //没有-l就换行
    if (!(kind & LSL))
    {
        printf("\n");
    }
}

//判断隐藏?
int ifhidefile(char *path) //原path+filename 目录后无/
{
    int wei = 0;
    for (int i = 0; i < strlen(path); i++)
    {
        if (path[i] == '/')
        {
            wei = i + 1;
        }
    }
    if (path[wei] == '.')
    {
        return 1;
    }
    else
        return 0;
}

//遍历目录下所有文件夹
void geteverydir(int kind, char *path)
{
    //  1.ls path
    printf("%s:\n", path);
    lsdir(kind, path);
    printf("\n");

    // count
    DIR *dir = NULL;
    struct dirent *p = NULL;
    int count = 0;
    struct stat a;
    int dircount = 0;
    int hidedircount = 0;
    int rightcount = 0;
    char *filename[MAXFILES];
    memset(&a, 0, sizeof(struct stat));

    for (int i = 0; i < MAXFILES; i++)
    {
        filename[i] = (char *)malloc(sizeof(char) * PATH_MAX);
        memset(filename[i], 0, PATH_MAX);
    }
    dir = opendir(path);
    if (dir == NULL)
    {
        printf("%s\n", path);
        for (int i = 0; i < MAXFILES; i++)
            free(filename[i]);
        myerror("opendir ", __LINE__);
    }
    while ((p = readdir(dir)) != NULL)
    {
        if (maxlen < strlen(p->d_name))
        {
            maxlen = strlen(p->d_name);
        }
        count++;
    }
    closedir(dir);
    if (count > MAXFILES)
    {
        for (int i = 0; i < MAXFILES; i++)
            free(filename[i]);
        myerror("two many files", __LINE__);
    }
    dir = opendir(path);
    if (dir == NULL)
    {
        for (int i = 0; i < MAXFILES; i++)
            free(filename[i]);
        myerror("opendir", __LINE__);
    }
    int lenpath = strlen(path);
    for (int i = 0; i < count; i++)
    {
        p = readdir(dir);
        if (p == NULL)
        {
            for (int i = 0; i < MAXFILES; i++)
                free(filename[i]);
myerror("readdir", __LINE__);
        }    
        if (strcmp(p->d_name, "..") == 0)
        {
            memset(filename[i], 0, PATH_MAX);
            continue;
        }
        else if (strcmp(p->d_name, ".") == 0)
        {
            memset(filename[i], 0, PATH_MAX);
            continue;
        }
        // path+file-/
        //dircount rightcount

        //printf("%s\n%s\n", filename[i], path);
        strncpy(filename[i], path, lenpath);
        filename[i][lenpath] = '\0';
        strcat(filename[i], p->d_name);
        filename[i][lenpath + strlen(p->d_name)] = '\0';

        memset(&a, 0, sizeof(struct stat));
        lstat(filename[i], &a);
        if (S_ISDIR(a.st_mode))
        {
            dircount++; //无. ..
            if (ifhidefile(filename[i]))
            {
                hidedircount++;
                if (!(kind & LSA)) //要隐藏
                {
                    memset(filename[i], 0, PATH_MAX);
                    continue;
                }
            }
            if (strlen(filename[i])) //不是隐藏
            {
                filename[i][strlen(filename[i])] = '/';
                filename[i][strlen(filename[i]) + 1] = '\0';
            }
        }
        else //不是目录
            memset(filename[i], 0, PATH_MAX);
    }
    if (kind & LSA)
        rightcount = dircount;
    else
        rightcount = dircount - hidedircount;
    closedir(dir);
    //快速排序
    int teemp[count];
    for (int i = 0; i < count; i++)
        teemp[i] = i;

    strqsort(filename, teemp, 0, count - 1);

    //递归
    //printf("%d\n", rightcount);
    //&& filename[teemp[i]][strlen(filename[teemp[i]]) - 1] == '/'
    for (int i = 0; i < count; i++)
    {

        if (0 == strlen(filename[teemp[i]]))
        {
            continue;
        }
        //printf("%d ", rightcount);
        if (rightcount)
        {

            maxlen = 0;
            rlen = MAXCHAR;
            rightcount--;
            geteverydir(kind, (char *)(filename[teemp[i]]));
        }
        else
        {

            printf("%s\n", filename[teemp[i]]);
            lsdir(kind, (char *)(filename[teemp[i]]));
            printf("\n");
        }
    }
    for (int i = 0; i < MAXFILES; i++)
        free(filename[i]);
    printf("\n");

    //printf("geteverydir over \n\n\n\n");
    //没有-l就换行
}
//处理路径 解析参数 分类状态处理
void dealpath(int kind, char *path)
{
    struct stat a;
    memset(&a, 0, sizeof(struct stat));
    if (lstat(path, &a) == -1)
    {
        printf("%s:\n", path);
        myerror("lstat", __LINE__);
    }
    if (S_ISDIR(a.st_mode))
    {
        if (kind & LSR)
            geteverydir(kind, path);
        else
        {
            printf("%s:\n", path);
            lsdir(kind, path);
        }
    }
    else
    {
        printf("%s:\n", path);
        lsfile(kind, path);
    }
}

int main(int argc, char **argv)
{
    //srand((unsigned int)time(NULL));
    //char path[PATH_MAX];
    char *path = (char *)malloc(sizeof(char) * PATH_MAX);
    memset(path, 0, sizeof(char) * PATH_MAX);
    int kind = LSNONE;
    int pathnumber = 0;
    //struct stat a;
    //int mode[250] = {0};
    //char temppath[PATH_MAX];

    //解析kind  -laR
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
                else if (argv[i][j] == 'R')
                {
                    kind |= LSR;
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

    //ls 不带路径(包含参数处理)
    if (argc == 1 || pathnumber == 0)
    {
        strcpy(path, "./");
        //lsdir(kind, path);
        dealpath(kind, path);
        printf("\n");
        free(path);
        return 0;
    }

    //解析多路径
    for (int i = 1; i < argc; i++)
    {
        memset(path, 0, PATH_MAX);
        if (argv[i][0] != '-') //不支持路径名带'-'
            explainfakepath(argv[i], path);
        else
            continue;

        dealpath(kind, path);
        printf("\n");
        maxlen = 0;
        rlen = MAXCHAR;
    }
    free(path);
    return 0;
}
