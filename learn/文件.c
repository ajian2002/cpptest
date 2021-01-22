#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    creat("/home/ajian/code/cpptest/learn/cin", S_IRWXU);
    int fp = open("/home/ajian/code/cpptest/learn/cin.in", O_RDONLY); //777  00700 S_IRWXU
    
    printf("%d\n", fp);
    close(fp);
    return 0;
}