#include <stdio.h>
#include <stddef.h>
int main()
{
    int su, i, sum;
    char a = '+', b = '-', c = '*', fu;
    scanf("%d", &su);
    int i[su + 1], k[su + 1];
    for (i = 0; i < su; i++)
    {

        if (getchar() == 'a')
            fu[i] = a;
        else if (getchar() == 'b')
            fu[i] = b;
        else if (getchar() == 'c')
            fu[i] = c;
        else
            fu[i] = fu[i - 1];

        scanf("%d %d", &j[i], &k[i]);
    }
    for (i = 0; i < su; i++)
    {

        printf("%d%c%d=", j[i], fu[i], k[i]);
        if (fu[i] == a)
        {
            printf("%d\n", j[i] + k[i]);
            printf("%d\n", );
        }
        else if (fu[i] == b)
        {
            printf("%d\n", j[i] - k[i]);
            printf("%d", );
        }
        else if (fu[i] == c)
        {
            printf("%d\n", j[i] * k[i]);
            printf("%d", );
        }
    }