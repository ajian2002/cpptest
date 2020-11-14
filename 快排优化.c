#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 100001
//void swap(int *a,int*b);
//void qsort(int *p, int l, int r);
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void qsort(int *p, int l, int r)
{
    // srand((unsigned int)time(NULL));

    int j = l, k = r;
    if (l < r)
    {
        int c;
        int temp;
        c = rand() % (r - l + 1) + l;
        temp = p[c];
        swap(&p[l], &p[c]);
        int jj = l + 1;
        /*
        for (int i = l + 1; i <= r; i++)//大到小
        {
            if (p[i] > temp)
            {
                swap(&p[i], &p[jj]);
                jj++;
            } 
        }
        */
        for (int i = l + 1; i <= r; i++) //小到大
        {
            if (p[i] < temp)
            {
                swap(&p[i], &p[jj]);
                jj++;
            }
        }
        // swap(&p[l], &p[jj]);
        qsort(p, jj, k);
        qsort(p, j, jj - 1);
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    int a[NUM] = {0};
    int i = 0, n = 0;
    //printf("输入数目个数");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int l = 0;
    int r = n - 1;
    qsort(a, l, r);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    //getchar();
}
