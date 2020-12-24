#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d", &t);
    int c[t];
    for (int i = 0; i < t; i++)
        c[i] = 0;
    for (int m = 0; m < t; m++)
    {
        int n;
        scanf("%d", &n);
        if (n == 1)
        {
            c[m] = 0;
            continue;
        }
        int s1[12350] = {0};
        int s2[12350] = {0};
        int al = 1;
        int bl = 1;
        int all = -1;
        int pre = -1;
        int len = 0;
        for (int f = 0; f < n; f++)
        {
            scanf("%d", &s1[f]);
            s2[s1[f]]++;
            if (s2[s1[f]] > al)
            {
                al = s2[s1[f]];
                all = s1[f];
            }
            if (s1[f] > len)
                len = s2[s1[f]];
        }
        int sum = 0;
        int this = 0;

        for (int i = 0; i <= len + 1; i++)
        {
            if (s2[i] > 0)
            {
                sum++;
                if (s2[i] == al)
                    sum--;
            }
        }
        c[m] = sum;
    }
    for (int i = 0; i < t; i++)
        printf("%d\n", c[i]);
}
