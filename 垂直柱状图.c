#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char ce[26] = {0};
    char sp[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int i, s, len, min, max;
    min = 1000;
    max = 0;

    char a[408], b[303], c[202], d[101];
    gets(a);
    gets(b);
    gets(c);
    gets(d);
    strcat(c, d);
    strcat(b, c);
    strcat(a, b);
    len = strlen(a);
    for (i = 0; i < 26; i++)
        sp[i] = toupper(sp[i]);
    for (i = 0; i < len; i++)
        for (s = 0; s < 26; s++)
            if (a[i] == sp[s])
            {
                ce[s]++;
                if (ce[s] > max)
                    max = ce[s];
            }
    int left, right, le, ri, sum;
    for (i = max; i > 0; i--)
    {
        sum = 0;
        while (sum < 26)
        {
            if (ce[sum] >= i)
                printf("* ");
            else
                printf("  ");
            sum++;
        }
        printf("\n");
    }
    for (i = 0; i < 26; i++)
        printf("%c ", sp[i]);
    getchar();
    return 0;
}
