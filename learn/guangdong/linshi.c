#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    unsigned long long c[t];
    for (int i = 0; i < t; i++)
    {
        int n, m, k;
        unsigned long long sum = 0;
        scanf("%d%d%d", &n, &m, &k);
        n = n / k;
        m = m / k;
        sum = n * m;
        c[i] = sum;
    }
    for (int i = 0; i < t; i++)
        printf("%llu\n", c[i]);
}