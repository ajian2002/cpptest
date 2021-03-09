#include <stdio.h>
//#include <math.h>
#include <string.h>
#include <math.h>
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
    int x[n + 1];
    memset(x, 0, 4 * (n + 1));
    x[0] = 2;
    x[1] = 3;
    x[2] = 5;
    //sushu(x, n);
    int left = 0;
    int right = 0;
    int temp = 2;
    int j = 0;
    for (int i = 4; i <= n; i += 2)
    {
        /*
        if (x[right] + x[left] == i)
        {
            printf("%d=%d+%d\n", i, x[left], x[right++]);
            continue;
        }
        if (i != x[left] + x[right])
        {
            for (int m = right + 1;; m++)
            {

                if (i == x[left] + x[m])
                {
                    right = m;
                    printf("%d=%d+%d\n", i, x[left], x[right]);
                    break;
                }
                if (i < x[left] + x[m])
                {
                    m--;
                    if (i == x[left + 1] + x[m])
                    {
                        left++;
                        right = m;
                        printf("%d=%d+%d\n", i, x[left], x[right]);
                        break;
                    }
                }
            }
        }
    }*/
        if (sushu(2) && sushu(i - 2))
        {
            printf("%d=%d+%d\n", i, 2, i - 2);
            continue;
        }
        if (sushu(3) && sushu(i - 3))
        {
            printf("%d=%d+%d\n", i, 3, i - 3);
            continue;
        }
        for (int j = 5; j < n; j += 2)
        {
            if (sushu(j) && sushu(i - j))
            {
                printf("%d=%d+%d\n", i, j, i - j);
                break;
            }
        }
    }
}
