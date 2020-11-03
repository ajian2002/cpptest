#include <stdio.h> //大至小
void qsort(int *p, int l, int r);
int main()
{
    int a[20] = {0};
    int i = 0, n = 0;
    printf("输入数目个数");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int l = 0;
    int r = n - 1;
    qsort(a, l, r);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void qsort(int *p, int l, int r)
{
    int j = l, k = r;
    if (l < r)
    {
        int temp = p[l];
        while (l != r)
        {
            while (l < r && p[r] > temp)
                r--;
            p[l] = p[r];
            while (l < r && p[l] < temp)
                l++;
            p[r] = p[l];
        }
        if (r == l)
            p[r] = temp;

        qsort(p, r + 1, k);
        qsort(p, j, r - 1);
    }
}
