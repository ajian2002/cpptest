#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    int len = n;
    char s[n + 1];
    scanf("%s", s);
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
    for (int i = 0; i < len - 2; i++)
    {
        if (i == 0 && s[i] == 'K' && s[i + 1] == 'K')
        {
            s[i] = 'V';
            break;
        }
        if (s[i] == 'K' && s[i + 1] == 'K' && s[i + 2] == 'K')
        {
            s[i + 1] = 'V';
            break;
        }
        if (s[i] == 'V' && s[i + 1] == 'V' && s[i + 2] == 'V')
        {
            s[i + 1] = 'K';
            break;
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