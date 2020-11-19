#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int a[10] = {0}; //[21,22,23]
    char b[50];
    scanf("%s", b);
    //  int i = 0;
    int size = 0, si = 0, i = 0;
    while (sscanf(b + size, "%*[][,]%d%n", &a[i], &si))
    {
        i++;
        size += si;
    }
    size = i;

    /*  int mol = 0, test = 0;
    for (int c = 0; c < i; c++)
    {
        if (test == 0)
        {
            mol = a[c];
        }
        else
        {
            for (int m = 0; m < i; m++)
            {
                /* code  if (a[m] == mol)
                {
                    test++;
                }
                else
                {
                    test--;
                }
            }
        }
        if (test > 0)
        {
        }
    }
失败的摩尔投票法*/
    int sum, test = 0;

    int large = 0;
    for (i = 0; i < size; i++)
    {
        int max = a[i];
        for (si = 0; si < size; si++)
        {
            if (a[si] == max)
            {
                test++;
                /* code */
            } /* code */
        }
        if (test > large)
        {
            large = test;
            test = 0;
            sum = max;
        }
    }
    if (large <= size / 2)
    {
        printf("-1");
        return 0;
        /* code */
    }

    printf("%d", sum);
}