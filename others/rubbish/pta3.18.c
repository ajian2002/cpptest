#include <stdio.h>
int main()
{
    int n;
    int count = 0;
    scanf("%d", &n);
    int s = 0;
    for (int i = 0; i < 1001; i++)
    {
        int temp = i;
        int sum = 0;
        while (temp)
        {
            int cc = temp % 10;
            temp /= 10;
            sum += cc;
        }
        if (sum == n)
        {
            printf("%8d", i);
            s++;
            if (s == 6)
            {
                s = 0;
                printf("\n");
            }
        }
    }
    if (s != 0)
    {
        printf("\n");
    }
}