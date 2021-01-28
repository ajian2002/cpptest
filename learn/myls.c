#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
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
int main(int argc, char **argv)
{
    struct stat f;
    if (argc != 2)
    {
        printf("usage: myls <filename>\n");
        //exit(1);
    }
    argv[1] = "/home/ajian/code/cpptest/learn/cin.in";
    int num = stat(argv[1], &f);
    if (num == -1)
    {
        perror("myls");
        exit(1);
    }
    //printf("%s", ctime(&f.st_mtim));
    //mon jan 25 23:35:09 2021\n\0
    //printf("%o",f.st_mode);33279->100 777

    return 0;
}