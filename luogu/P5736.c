#include <math.h>
#include<stdio.h>
int sushu(int sss)
{
    int i;
    int part = sqrt(sss);
    // printf("%d", part);
    if (sss == 1 || sss == 0)
    {
        return 0;
    }
    else
    {
        for (i = 2; i <= part; i++)
        {
            if (sss % i == 0)
                return 0;
        }

        return 1;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int x[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        int xd;
        scanf("%d", &xd);
        if (sushu(xd))
            x[j++] = xd;
    }
    for (int i = 0; i < j; i++)
        printf("%d ", x[i]);
}