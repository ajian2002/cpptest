#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
int main()
{
    int fc = creat("/home/ajian/code/cpptest/learn/cin", S_IRWXU);
    int fo = open("/home/ajian/code/cpptest/learn/cin.in", O_RDONLY); //777  00700 S_IRWXU
    printf("%d,%d,%d\n", fc, fo, errno);                              //3 4
    char *s = (char *)malloc(sizeof(char) * 10);
    memset(s, '\0', sizeof(char) * 10);
    read(fo, s, 5);
    printf("%s\n", s);
    close(fo);
    free(s);
    //perror("abc");
    //默认有   str: status
    //printf("aa :%s     \n", strerror(errno));
    return 0;
}