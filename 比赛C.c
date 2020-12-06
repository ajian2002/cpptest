#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    int n[t + 1], k[t + 1];
    int i, j, ci, yu;
    unsigned long long sum, sum1;
    for (i = 0; i < t; i++)
        scanf("%d%d", &n[i], &k[i]);
    int m[100000];
    int f[1000] = {0};
    for (i = 0; i < t; i++)
    {
        if (k[i] > n[i])
            k[i] = n[i];
        ci = n[i] / k[i];
        yu = n[i] % k[i];
        sum = 0;
        sum1 = 0;
        int p = 0, max = 0;
        for (j = 1; j <= k[i]; j++)
        {
            m[j] = ci;
            if (yu > 0)
            {
                m[j]++;
                yu--;
            }
            sum1 = m[j];

            while (sum1 > 0)
            {
                f[p++] += sum1 % 10;
                sum1 /= 10;
                if (f[p - 1] > 9)
                {
                    f[p]++;
                    f[p - 1] -= 10;
                }
                if (p > max)
                    max = p;
            }
            p = 0;
        }

        while (max >= 0)
        {
            //printf("%d", f[max]);
            max--;
        }

        for (j = 1; j <= k[i]; j++)
        {
            sum += m[j] * ((k[i] - j) * ci);
        }
        printf("%d\n", sum);
    }
    //printf("\n");
    //    / return 0;
}