#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>
int sushu(int sss)
{
    int i;
    int part = pow(sss, 0.5);
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
    long int m, n;
    m = 0, n = 0;
    scanf("%ld", &n);
    //printf("n:%ld\n", n);
    for (long int i = 2; i < n / 2 + 1; i++)
    {

        if (sushu(i) == 1)
        {

            if (1 == sushu(n - i))
            {

                printf("%ld = %ld + %d\n", n, i, (int)(n - i));
                return 0;
            }
        }
    }
    return 0;
}