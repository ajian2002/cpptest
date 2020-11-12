#define NUM 90
#include <stdio.h>
#include <stdlib.h>
//#define MAX(a, b) (a > b) ? a : b
/*#define MALLOC(TYPE, N) \
    ((TYPE *)malloc((N) * sizeof(TYPE)))
*/
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
}
int main()
{
    int a[NUM] = {0};
    QSORT(a, 0, NUM - 1);
    for (int i = 0; i < NUM; i++)
        printf("%d ", a[i]);

    return 0;
}