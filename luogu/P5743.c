#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int num = 1;
    if (n == 1)
    {
        printf("1");
        return 0;
    }
    for (int i = 2; i <= n; i++)
    {
        num = 2 * num + 2;
    }
    printf("%d", num);
    return 0;
}