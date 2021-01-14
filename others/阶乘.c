#include <stdio.h>
unsigned long long jiecheng(int n)
{
    unsigned long long sum = 0;
    unsigned long long sum1 = 1;
    for (int i = 1; i <= n; i++)
    {
        int ss = i;
        while (ss > 0)
        {
            sum1 *= ss;
            ss--;
        }
        sum += sum1;
        sum1 = 1;
        //printf("%d\n", sum);
    }
    return sum;
}
int main()
{
    int n, x, s1, s2;
    scanf("%d", &n);
    unsigned long long sum2 = jiecheng(n);
    printf("%u", sum2);
    return 0;
}
