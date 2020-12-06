#include <stdio.h>
int main()
{
    int n, j, k, i, l, m;
    scanf("%d", &n);
    int nl = 1;
    for (i = 1; i <= n; i++)
    {
        nl *= i;
    }
    printf("%d", nl);
}