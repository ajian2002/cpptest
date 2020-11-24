#define NUM 90
#include <stdio.h>
#include <stdlib.h>
//#define MAX(a, b) (a > b) ? a : b
/*#define MALLOC(TYPE, N) \
    ((TYPE *)malloc((N) * sizeof(TYPE)))
*/
/*
#define QSORT(*p, l, r)                       \
    {                                         \
        if (l < r)                            \
        {                                     \
            int ll = l;                       \
            int rr = r;                       \
            while (l < r)                     \
            {                                 \
                int temp = p[r];              \
                while (l < r && p[r] >= temp) \
                    r--;                      \
                p[l] = p[r];                  \
                while (l < r && p[l] <= temp) \
                    l++;                      \
                p[r] = p[l];                  \
            }                                 \
            if (l == r)                       \
                p[r] = temp;
}
}*/
int main()
{
    int a = 1;
    double temp = 1.2;
    void *p = &a;
    void *q = &temp;
    //    printf("%d,%f", *(int *)(p), *(double *)(q));
    while (--a)
    {
        printf("1");
    }
    return 0;
}