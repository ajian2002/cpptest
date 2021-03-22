#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
void re(int c)
{
    pid_t pid;
    pid = fork();
    if (errno == EAGAIN)
    {
        printf("last number is %d\n", c);
        perror("errno is EAGAIN");
        exit(-1);
    }
    if (pid == -1)
    {
        printf("last number is %d\n", c);
        perror("fork failed");
        exit(-1);
    }
    switch (pid)
    {
    case 0:
        printf("%d\n", ++c);
        re(c);
        break;
    default:
        printf("%d\n", c);
        int status;
        wait(&status);
        break;
    }
}
int main()
{
    int c = 1;
    re(c);
}