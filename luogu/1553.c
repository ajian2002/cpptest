#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void arint(char *s, int len1);
int main()
{
    char s[25];
    scanf("%s", s);
    int len = strlen(s);
    if (strchr(s, '.') != NULL)
    {

        int len1 = strchr(s, '.') - s;
        char s1[len];
        memset(s1, 0, len);
        memcpy(s1, s, len1);
        arint(s1, len1);
        if (s1[0] == '-')
            printf("-");

        /* int is = 0;
            for (int i = 0; i- < len1; i++)
            {
                if (is == 0 && s1[i] == '0')
                    continue;
                else
                {
                    printf("%c", s1[i]);
                    if (s1[i] != '-')
                        is = 1;
                }
            }*/
        long int xi = atol(s1);
        if (xi < 0)
            xi = -1 * xi;
        printf("%ld", xi);

        printf(".");
        memset(s1, 0, len);
        memcpy(s1, strchr(s, '.') + 1, len - 1 - len1);
        arint(s1, len - 1 - len1);
        long int xiao = atol(s1);
        if (xiao != 0)
        {
            while (xiao > 0 && xiao % 10 == 0)
                xiao /= 10;
        }
        printf("%ld", xiao);
    }
    else if (strchr(s, '/') != NULL)
    {
        int len1 = strchr(s, '/') - s;
        char s1[len];
        memset(s1, 0, len);
        memcpy(s1, s, len1);
        if (s1[0] == '-')
            printf("-");
        arint(s1, len1);
        long int xi = atol(s1);
        if (xi < 0)
            xi = -1 * xi;
        printf("%ld", xi);
        /* for (int i = 0; i < len1; i++)
        {
            if (is == 0 && s1[i] == '0')
                continue;
            else
            {
                printf("%c", s1[i]);
                if (s1[i] != '-')
                    is = 1;
            }
        }*/
        printf("/");
        memset(s1, 0, len);
        memcpy(s1, strchr(s, '/') + 1, len - 1 - len1);
        arint(s1, len - 1 - len1);
        xi = atol(s1);
        printf("%ld", xi);
    }
    else if (strchr(s, '%') != NULL)
    {
        len--;
        arint(s, len);
        long int xiao = atol(s);
        printf("%ld", xiao);
        printf("%%");
    }
    else
    {
        arint(s, len);
        long int xiao = atol(s);
        printf("%ld", xiao);
    }
}
void arint(char *s, int len1)
{
    char temp;
    if ((s[0] == '0' && len1 == 1) || (s[0] == '-' && s[1] == '0' && len1 == 2))
    {
        return;
    }
    int i = 0, r = len1 - 1;
    if (s[0] == '-')
    {
        i++;
    }
    if ((i + len1) % 2 == 1) //ji
    {

        while (i != r)
        {
            temp = s[r];
            s[r] = s[i];
            s[i] = temp;
            r--;
            i++;
        }
    }
    else
    {

        while (i < r)
        {
            temp = s[r];
            s[r] = s[i];
            s[i] = temp;
            r--;
            i++;
        }
    }
}