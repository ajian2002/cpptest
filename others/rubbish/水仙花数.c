#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int n;
    //char c;
    //char s[100] = {0};
    scanf("%d", &n);
    long sum = 0;
    int m, cc, d;
    for (int i = pow(10, n - 1); i < pow(10, n); i++)
    {
        sum = 0;
        m = i;
        d = i;
        while (m > 0)
        {
            cc = m % 10;
            m /= 10;
            switch (cc)
            {
            case 0:
                sum += 0;
                break;
            case 1:
                sum += 1;
                break;
            default:
                sum += pow(cc, n);
                break;
            }
            if (sum > i)
            {
                i += 10 - i % 10 - 1;
                break;
            }
        }

        if (m <= 0 && sum == d)
        {
            printf("%d\n", d);
        }
    }
}