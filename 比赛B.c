#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    int n[t], k[t];
    int i, j;
    for (i = 0; i < t; i++)
        scanf("%d %d", &n[i], &k[i]);
    for (i = 0; i < t; i++)
    {
        int sum = n[i];
        if (n[i] >= k[i])
        {
            int x = n[i] / k[i];
            n[i] -= x * k[i];
        }
        if (n[i] == 0)
        {

            printf("0");
            if (i != t - 1)
                printf("\n");
            continue;
        }
        else
        {
            printf("%d\n", n[i]);
            for (j = sum - n[i] + 1; j <= sum; j++)
            {
                printf("%d", j);
                if (j != sum)
                    printf(" ");
            }
            if (i != t - 1)
                printf("\n");
        }
    }
}