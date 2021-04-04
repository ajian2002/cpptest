#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int x;
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        char s[106];
        scanf("%s", s);
        if (strlen(s) < 3)
        {
            printf("0\n");
            continue;
        }

        for (int m = 3; m <= strlen(s); m++)
        {
            for (int j = 0; j <= strlen(s) - 3; j++)
            {
                int le = j;
                int ri = j + m - 1;
                while (le < ri)
                {
                    if (s[le] == s[ri])
                    {
                        le--;
                        ri++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (le == ri || le > ri)
                {
                }
            }
        }
    }
}