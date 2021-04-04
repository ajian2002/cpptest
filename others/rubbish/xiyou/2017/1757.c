#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void qsqort(int *p, int l, int r)
{
    // srand((unsigned int)time(NULL));

    int j = l, k = r;
    if (l < r)
    {
        int c;
        int temp;
        c = rand() % (r - l + 1) + l;
        temp = p[c];
        swap(p + l, &p[c]);
        int jj = l + 1;
        /*
        for (int i = l + 1; i <= r; i++)//大到小
        {
            if (p[i] > temp)
            {
                swap(&p[i], &p[jj]);
                jj++;
            } 
        }
        */
        for (int i = l + 1; i <= r; i++) //小到大
        {
            if (p[i] < temp)
            {
                swap(&p[i], &p[jj]);
                jj++;
            }
        }
        // swap(&p[l], &p[jj]);
        qsqort(p, jj, k);
        qsqort(p, j, jj - 1);
    }
}
int main()
{
    int t;
    srand((unsigned int)time(NULL));
    scanf("%d", &t);
    int c[t];
    for (int i = 0; i < t; i++)
        c[i] = 0;
    for (int m = 0; m < t; m++)
    {
        int n;
        scanf("%d", &n);
        int s1[12350] = {0};
        int s2[12350] = {0};

        int len = 1;
        int al = 1;
        int bl = 1;
        int all = 0;
        int pre = 0;
        for (int f = 0; f < n; f++)
        {
            scanf("%d", &s1[f]);
            s2[s1[f]]++;
            if (s2[s1[f]] > al && s2[s1[f]] > s2[pre])
            {
                al = s2[s1[f]];
                all = s1[f];
            }
            else if (s2[s1[f]] >= bl && s2[s1[f]] <= s2[all])
            {
                if (s2[all] == 0)
                {
                    all = s1[f];
                }
                else
                {
                    bl = s2[s1[f]];
                    pre = s1[f];
                }
            }
            else if (s2[s1[f]] == 1 && pre == 0)
                pre = s1[f];
        }
        //  qort(s1, 0, n - 1);

        //qsqort(s2, 0, len);
        /*
        int max = s2[len];
        if (s2[len] == s2[len - 1] && s2[len - 1] != 0)
        {
            c[m] = 0;
            continue;
        }
        if (s2[len - 1] == 0)
        {
            c[m] = 0;
            continue;
        }

        if (s2[len - 1] != 0)
        {
            c[m] = all;
            continue;
        }
    
    */
        if (s2[pre] == s2[all])
            c[m] = 0;
        if (s2[all] != s2[pre] && s2[pre] != 0 && s2[all] != 0)
        {
            if (s2[pre] > s2[all])
                c[m] = pre;
            else
                c[m] = all;
        }
        else
        {
            c[m] = 0;
        }
    }
    for (int i = 0; i < t; i++)
        printf("%d\n", c[i]);
}