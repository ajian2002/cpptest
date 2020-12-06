#include <stdio.h>
#include <string.h>
int main()
{
    char a[101], c[26] = {0};
    char sp[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int i, s, len, min, max;
    char MAX, MIN;
    min = 1000;
    max = 0;
    scanf("%s", a);
    len = strlen(a);
    for (i = 0; i < len; i++)
    {
        for (s = 0; s < 26; s++)
        {
            if (a[i] == sp[s])
                c[s]++;
        }
    }
    for (i = 0; i < 26; i++)
    {
        printf("%c出现了%d次\n", sp[i], c[i]);
    }
    /* for (s = 0; s < 26; s++)
    {
        if (c[s] != 0)
        {
            if (c[s] > max)
            {
                max = c[s];
                MAX = sp[s];
            }
            if (c[s] < min)
            {
                min = c[s];
                MIN = sp[s];
            }
        }
        continue;
    }
*/

    return 0;
}