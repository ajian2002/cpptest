#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    int len = n;
    char s[n + 2];

    scanf("%s", s);
    s[n] = 'V';

    if (n <= 2)
    {
        if (n < 2)
        {
            printf("0");
            return 0;
        }
        else
        {
            if (s[0] == 'K' && s[1] == 'V')
                printf("0");
            else
                printf("1");
            return 0;
        }
    }
    int ci = 1;
    for (int i = 0; i < len - 1; i++)
    {
        if (ci && s[i] == 'K' && s[i + 1] == 'K' && s[i + 2] == 'K')
        {
            ci--;
            s[i + 1] = 'V';
            break;
        }
        if (ci && s[i] == 'V' && s[i + 1] == 'V' && s[i + 2] == 'V')
        {
            ci--;
            s[i + 1] = 'K';
            break;
        }
    }
    if (ci)
    {
        for (int i = len - 1; i >= 0; i--)
        {
            if (ci && s[i] == 'K' && i - 1 >= 0)
            {
                if (s[i - 1] == 'V')
                    continue;
                else if (i - 2 >= 0)
                    continue;
                else
                {
                    s[i - 1] = 'V';
                    ci--;
                    break;
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < len - 1; i++)
    {

        if (s[i] == 'V' && s[i + 1] == 'K')
        {
            sum++;
            i++;
        }
    }
    printf("%d", sum);
}