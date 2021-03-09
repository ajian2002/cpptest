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
            scanf("%d", &c[m]);
            continue;
        }
        int s1[12350] = {0};
        int s2[12350] = {0};
        int al = 1;
        int bl = 1;
        int all = -1;
        int pre = -1;
        for (int f = 0; f < n; f++)
        {
            scanf("%d", &s1[f]);
            s2[s1[f]]++;

            if (all == -1)
            {
                all = s1[f];
                continue;
            }
            if (pre == -1 && all != -1)
            {
                if (s1[f] == all)
                {
                    pre = -1;
                    al++;
                }
                else
                    pre = s1[f];
                continue;
            }
            if (s2[s1[f]] > al && s1[f] != pre)
            {
                all = s1[f];
                al = s2[s1[f]];
            }
            else if (s2[s1[f]] > bl && all != s1[f])
            {
                bl = s2[s1[f]];
                pre = s1[f];
            }
        }

        if (s2[all] == s2[pre])
        {
            c[m] = 0;
            continue;
        }
        else if (s2[all] > s2[pre] && s2[pre] != -1)
        {
            c[m] = s2[all];
            continue;
        }
        else if (s2[all] > s2[pre] && s2[pre] == -1)
        {
            c[m] = 0;
            continue;
        }
        else if (s2[all] < s2[pre])
        {
            c[m] = s2[pre];
            continue;
        }
    }
    for (int i = 0; i < t; i++)
        printf("%d\n", c[i]);
}