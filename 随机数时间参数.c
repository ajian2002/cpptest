#include <stdio.h>
#include <stdlib.h>
#include "test2.c"
#include <time.h>
int a = 3;
static int b;
#define b B
typedef int INT;
void ssr(int, int);
//extern arr();
int main()
{
    INT DDE = 21;
    // scanf("%d", &DDE);
    srand((unsigned int)time(0));
    printf("%d\n", rand());
    ssr(3, 2);
    printf("%d\n", a);
    //  B = 4;
    //  printf("%d", B);
    arr();
}
void ssr(int, int)
{
    int a = 10;
    printf("%d\n", a);
}