#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char fi[50];
    fgets(fi, 500, stdin);
    char re[1000001];
    fgets(re, 1000001, stdin);
    int lens = strlen(re) - 1;
    int lenf = strlen(fi) - 1; //2
    re[lens] = ' ';
    re[lens + 1] = '\0';
    int sum = 0;
    int zz = -283;
    for (int i = 0; i <= lens; i++)
    {
        if ((re[i] == ' ' && i != lens) || i == 0)
        {
            int test = 0, ci = i + 1;
            if (i == 0)
                ci--;
            for (int j = 0; j < lenf; j++)
            {
                if (re[ci] == ' ')
                {
                    break;
                }
                if (tolower(re[ci]) == tolower(fi[j]))
                {
                    ci++;
                    test++;
                }
                else
                    break;
                if (test == lenf && re[ci] == ' ')
                {
                    sum++;
                    if (sum == 1)
                    {
                        if (i == 0)
                            zz = 0;
                        else
                            zz = i + 1;
                    }
                }
            }
        }
    }
    if (zz == -283)
    {
        printf("-1");
        return 0;
    }
    printf("%d %d", sum, zz);
}