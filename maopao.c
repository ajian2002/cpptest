#include <stdio.h>
int main()
{
    int j, l, i, t, min, a[50];
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d", &a[i]);
    }
    for (j = 1; j < t; j++)
    {
        for (l = 1; l < t; l++)
        {
            if (a[l - 1] > a[l])
            {
                min = a[l];
                a[l] = a[l - 1];
                a[l - 1] = min;
                /* code */
            }
        }

        /* code */
    }
    for (i = 0; i < t; i++)
    {
        printf("%d ", a[i]);
        /* code */
    }
    return 0;
}