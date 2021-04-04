#include <stdio.h> //大至小
#define NUM 1000
void qsort(int *p, int l, int r)
{
    int j = l, k = r;
    if (l < r)
    {
        int temp = p[l];
        while (l != r)
        {
            while (l < r && p[r] >= temp)
                r--;
            // if (l != r)
            p[l] = p[r];
            while (l < r && p[l] <= temp)
                l++;
            //if (l != r)
            p[r] = p[l];
        }
        if (r == l)
            p[r] = temp;

        qsort(p, r + 1, k);
        qsort(p, j, r - 1);
    }
}
void strqsort(int *before, int *now, int l, int r)
{
    int j = l, k = r;
    if (l < r)
    {
        int temp = now[l];
        while (l != r)
        {
            while (l < r && before[now[r]] - before[temp] >= 0)
                r--;
            //p[l] = p[r];
            now[l] = now[r];
            while (l < r && before[now[l]] - before[temp] <= 0)
                l++;
            //p[r] = p[l];
            now[r] = now[l];
        }
        if (r == l)
            now[r] = temp;

        strqsort(before, now, r + 1, k);
        strqsort(before, now, j, r - 1);
    }
}

int main()
{
    int before[NUM] = {0};
    int i = 0, n = 0;
    //printf("输入数目个数");
    scanf("%d", &n);
    int now[n];
    for (i = 0; i < n; i++)
    {
        now[i] = i;
        scanf("%d", &before[i]);
    }

    int l = 0;
    int r = n - 1;
    strqsort(before, now, l, r);

    for (i = 0; i < n; i++)
        printf("%d ", before[now[i]]);
}
