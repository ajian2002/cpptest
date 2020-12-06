#include <stdio.h>
int main(int argc, char argv[])
{
    int n;
    scanf("%d", &n);
    int n2 = (n) * (n);
    int a[n * n + 2 * n + 2]; //在C中，使用变量来定义数组长度是，这个数组可以定义，却不能同时进行初始化赋值，需要在之后赋值。
    for (int i = 0; i < n2; i++)
        a[i] = 0;
    //int a[n + 1][n + 1] = {0};
    int q, p;
    q = 0;
    int sum = 0;
    for (int i = 0; i < n2; i++)
    {

        scanf("%d", &p);
        sum += p;
        if (i % 2 == 0)
        {
            q += p;
        }
        else
        {
            for (int k = q; k < q + p; k++)
            {
                a[k] = 1;
            }
            q += p;
        }
        if (sum == n2)
            break;
    }
    int x = 0;

    //输出
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", a[x++]);
        }
        printf("\n");
    }

    // for (int i = 0; i < n2; i++)
    //   printf("%d", a[i]);
}