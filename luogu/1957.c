#include <stdio.h>
#include <math.h>
int getci(int s1, int s2, int sum)
{
    int wei = 2;
    if (s1 == 0)
        wei++;
    if (s1 < 0)
    {
        wei++;
        s1 = -1 * s1;
    }
    if (s2 == 0)
        wei++;
    if (s2 < 0)
    {
        wei++;
        s2 = -1 * s2;
    }
    if (sum == 0)
        wei++;
    if (sum < 0)
    {
        wei++;
        sum = -1 * sum;
    }
    while (s1 > 0)
    {
        wei++;
        s1 /= 10;
    }
    while (s2 > 0)
    {
        wei++;
        s2 /= 10;
    }
    while (sum > 0)
    {
        wei++;
        sum /= 10;
    }
    return wei;
}
int main()
{

    int n;
    char tt;
    scanf("%d", &n);
    if (getchar() == '\r')
        getchar();
    for (int k = 1; k <= n; k++)
    {
        char fu;
        fu = getchar();
        if (fu == 'a')
        {
            int s1, s2;
            scanf("%d%d", &s1, &s2);
            int sum = s1 + s2;
            printf("%d+%d=%d\n", s1, s2, sum);
            int wei = 2;
            wei = getci(s1, s2, sum);
            printf("%d\n", wei);
            tt = fu;
        }
        else if (fu == 'b')
        {
            int s1, s2;
            scanf("%d%d", &s1, &s2);
            int sum = s1 - s2;
            printf("%d-%d=%d\n", s1, s2, sum);
            int wei = 2;
            wei = getci(s1, s2, sum);
            printf("%d\n", wei);
            tt = fu;
        }
        else if (fu == 'c')
        {
            int s1, s2;
            scanf("%d%d", &s1, &s2);
            int sum = s1 * s2;
            printf("%d*%d=%d\n", s1, s2, sum);
            int wei = 2;
            wei = getci(s1, s2, sum);
            printf("%d\n", wei);
            tt = fu;
        }
        else
        {
            int s1 = fu - '0';
            char c = getchar();
            while (c != ' ')
            {
                s1 = s1 * 10 + c - '0';
                c = getchar();
            }
            int s2;
            scanf("%d", &s2);
            if (tt == 'a')
            {
                int sum = s1 + s2;
                printf("%d+%d=%d\n", s1, s2, sum);
                int wei = 2;
                wei = getci(s1, s2, sum);
                printf("%d\n", wei);
            }
            else if (tt == 'b')
            {
                int sum = s1 - s2;
                printf("%d-%d=%d\n", s1, s2, sum);
                int wei = 2;
                wei = getci(s1, s2, sum);
                printf("%d\n", wei);
            }
            else if (tt == 'c')
            {
                int sum = s1 * s2;
                printf("%d*%d=%d\n", s1, s2, sum);
                int wei = 2;
                wei = getci(s1, s2, sum);
                printf("%d\n", wei);
            }
        }
        if (k != n)
        {
            if (getchar() == '\r')
                getchar();
        }
    }
}