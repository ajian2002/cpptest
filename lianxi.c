#include <stdio.h>

struct B
{
    int c[100];
    char as;
    double aa;
    float asd;
};
struct B b1;

void qsort(int *p, int l, int r);
int main()
{
    //int m[100];

    int n = 0;

    do
    {
        scanf("%d", &b1.c[n]);
        n++;
    } while (getchar() != '\n');

    qsort(b1.c, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", b1.c[i]);

    return 0;
}
void qsort(int *p, int l, int r)
{
    int j = l, k = r;
    int temp = p[l];
    if (l < r)
    {
        while (l != r)
        {
            while (l < r && p[r] >= temp)
                r--;
            p[l] = p[r];
            while (l < r && p[l] <= temp)
                l++;
            p[r] = p[l];
        }
        if (r == l)
            p[r] = temp;
        qsort(p, j, r - 1);
        qsort(p, r + 1, k);
    } //if判断必须包括递归
}
