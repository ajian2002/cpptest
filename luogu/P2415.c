#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int a;
    int b[1001] = {0};
    unsigned long long sum = 0;
    int j = 0, count = 0;
    int max = 0;
    while (scanf("%d", &a) != EOF)
    {

        /*  if (b[a] == 0)
        {
            b[a] = 1;
            count++;
            sum += a;
        }*/
        count++;
        sum += a;
    }
    //    printf("%d ", count);
    int len = count;
    //    printf("%d %d %llu\n", len, pow(2, len - 1), sum);
    sum = pow(2, len - 1) * sum;
    printf("%llu", sum);
}