#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#define NUM 1000
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/*
void sq(void *p, size_t n, size_t s)
{
    int j = *p;
    int k = *(p + n);
    printf("%p,%p", j, k);
}*/
int main()
{
    // qsort();
    int len = 10;
    // srand((unsigned int)time(NULL));
    int a[len] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    //int n = sizeof(a) / sizeof(a[0]);
    //  printf("%d\n", n);
    printf("%d", 1 > 1);
    //int *l = &a[0];
    //printf("%p %p %p %p\n", &a, &a[1], &a[7], &a[8]);
    //printf("%p %p\n", l++, r--);
    //printf(" %d ", *r);
    // printf("%p %p", l, r);
    // sq(a, (sizeof(a) - 1) / sizeof(a[0]), sizeof(int));
    // int c = rand() % (r + 1 - l) + l;
    //  printf("%p,%p", )
}
