#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define COW 4
void srr(int a[][COW], int t, int m);
int main(int argc, char *argv[])
{
    unsigned int ss;
    //  printf("%s", argv[0]);
    //printf("%s ", argv[1]);
    //printf("%s ", argv[2]);
    //printf("%s ", argv[3]);
    srand((unsigned int)time(0));
    ss = rand();
    printf("%d", ss);
}
