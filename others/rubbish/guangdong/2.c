#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void cao(int num, int x, int c[], int add)
{
    if (num == 1)
    {
        c[x] = -551;
    }
    else if (num == 2)
    {
        c[0] = c[x];
        c[x] = -888;
    }
    else if (num == 3)
    {
        c[0] = c[x];
        int temp = c[x];
        c[x] = -521;
        int z = x;
        while (c[z + 1] == temp)
        {
            c[0] += c[z + 1];
            z++;
        }
        c[x + 1] = z + 1;
    }
}
int main()
{
    int t, n, q, sum;
    scanf("%d%d", &n, &q);
    int c[n + 101];
    int b[101] = {0};
    int d[n + 105];
    b[0] = 1;
    int i;
    for (i = 1; i < n + 1; i++)
    {
        scanf("%d", &c[i]);
        b[i] = i + 1;
    }
    b[n - 1] = n;
    b[n] = 0;
    int add = 0;
    for (i = 0; i < q; i++)
    {
        int num, x;
        add = 0;
        scanf("%d", &num);

        if (num != 2)
        {
            scanf("%d", &x);
            cao(num, x, c, 0);
        }
        else
        {
            scanf("%d%d", &x, &add);
            cao(num, x, c, add);
        }
        int j = 1;

        for (int f = 1; f < n + 1; f++)
        {
            if (c[f] != -551 && c[f] != -888 && c[f] != -521)
            {
                //   printf("%d ", c[f]);
                d[j++] = c[f];
            }
            if (c[f] == -888)
            {
                //     printf("%d ", add);
                d[j++] = add;
                //      printf("%d ", c[0]);
                d[j++] = c[0];
            }
            if (c[f] == -521)
            {
                //        printf("%d ", c[0]);
                d[j++] = c[0];
                f = c[x + 1] - 1;
            }
        }
        memset(c, 0, sizeof(c));
        memcpy(c, d, sizeof(int) * j);
        for (int k = 1; k < j; k++)
            printf("%d ", d[k]);
        n = j - 1;
        printf("\n");
    }
}