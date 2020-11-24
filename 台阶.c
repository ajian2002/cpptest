#include <stdio.h>
int taijie(int *a, int n);
int zuobi(int n);
int main()
{
    int n, sum1;
    scanf("%d", &n);
    int a[n + 1];
    a[0] = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    //  sum = taijie(a, n);
    sum1 = zuobi(n);
    printf("%d", sum1);
}
int zuobi(int n)
{
    if (n == 1)
        return 1;
    int x = 1;
    for (int i = 1; i < n; i++)
    {
        x *= 2;
        if (n < x)
        {
            x = i;
            break;
        }
    }
    return x;
}

/*
int taijie(int *a, int n)
{
    // int a[0] = 0;
    int x = n;
    int sum = 0;
    while (x > 0) //奇数-1
    {
        if (x % 2 == 0)
            continue;
        else
            a[x]--;
        x--;
    }
    sum++;
    x = n;
    a = &a[1];
    return 0;
}
*/