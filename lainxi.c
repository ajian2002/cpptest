#include <stdio.h>
#include <stdlib.h>
#define MAX 35
struct teme
{
    char name[MAX];
    char *name1 = "stddef";
};
int main(int argc, char *argv[])
{
    struct teme A;
    scanf("%s", A.name);
    scanf("%s", A.name1);
    printf("%p   %p", A.name, A.name1);
}