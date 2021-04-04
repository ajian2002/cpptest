#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    int c[t];
    for (int i = 0; i < t; i++)
    {
        int n, m, k;
        int sum = 0;
        scanf("%d%d%d", &n, &m, &k);
        /*       for (int i = k; i <= n; i += k)
        {
            for (int j = k; j <= m; j += k)
            {
                if (j % k == 0)
                {
                    if (i % k == 0)
                        sum += 1;
                }
            }
        }
   */
        n = n / k;
        m = m / k;
        sum = n * m;
        c[i] = sum;
    }
    for (int i = 0; i < t; i++)
        printf("%d\n", c[i]);
}