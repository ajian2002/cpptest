#include <stdio.h>
#include <string.h>
int main()
{
    char a[26] = {'A',
                  'B',
                  'C',
                  'D',
                  'E',
                  'F',
                  'G',
                  'H',
                  'I',
                  'J',
                  'K',
                  'L',
                  'M',
                  'N',
                  'O',
                  'P',
                  'Q',
                  'R',
                  'S',
                  'T',
                  'U',
                  'V',
                  'W',
                  'X',
                  'Y',
                  'Z'};
    char b[50];
    int c[26] = {0};
    scanf("%s", b);
    int i, z, len;
    len = strlen(b);
    for (i = 0; i < len; i++)
    {
        for (z = 0; z < 26; z++)
        {
            if (b[i] == a[z])
                c[z]++;
        }
    }
    for (i = 0; i < 26; i++)
        printf("%c  %d\n", a[i], c[i]);
    return 0;
}
