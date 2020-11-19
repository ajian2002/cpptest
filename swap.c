#include <stdio.h> //大小端深刻理解
#include <string.h>
void swap(int **a, int **b)
{
    int *c = *a;
    *a = *b;
    *b = c;
}
int main()
{
    int a = 1, b = 2;
    int *pa = &a;
    //s;
    //sscanf();
    int *pb = &b;
    printf("%p,%p\n", &a, &b);
    swap(&pa, &pb);
    //printf("%p,%p\n", pa, pb);
    return 0;
    // printf("%zu\n", sizeof(int));
    // printf("%d,%d\n", a, b);
    //printf("%x \n%x", p, *(char *)((int)(&x) - 1));
}
