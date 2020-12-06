#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n], b[n];
    int i, j, bs = 0, as = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        as += a[i];
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        bs += b[i];
    }
    int m[100] = {0};
    unsigned long long s = 0;
    j = 0;
    int max = 0;
    for (i = 0; i < n; i++)
    {
        //     int m[i] = s;
        s = a[i] * bs;
        while (s > 0)
        {
            m[j++] += s % 10;
            s /= 10;
            if (m[j - 1] > 9)
            {
                m[j]++;
                m[j - 1] -= 10;
            }
            if (j > max)
                max = j;
        }
        j = 0;

    } // sum[i] += a[i] * b[j];
    printf("%d", as * bs);
    while (max >= 0)
    {
        //printf("%d", m[max]);
        max--;
    }
}