#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void autoint(char *p, int *q)
{

    int i = 0;
    if (p[0] == '-')
        i = 1;

    for (; i < strlen(p); i++)
        q[i] = p[i] - '0';
}

int main()
{
    int x = 123;
    char a[15] = {'0'};
    int b[15] = {0};

    sprintf(a, "%d", x);

    autoint(a, b);

    int len = strlen(a);
    int j = 0, k = len - 1, IF = 0;
    if (a[0] == '-')
    {
        IF = 1;
        len--;
        j++;
    }

    int jj = j, kk = k;

    while (jj < kk)
    {
        int temp = b[kk];
        b[kk] = b[jj];
        b[jj] = temp;
        jj++;
        kk--;
    }

    int summ = 0, sum, sum1;

    while (j - 1 != k)
    {
        sum = 10 * summ + b[j];

        if ((10 * sum + b[j + 1]) < (2 ^ 31 - 1))
            return 0;
        else
            summ = sum;
        j++;
    }
    if (IF)
        return -summ;
    //printf("%d", summ);
    return summ;
}
