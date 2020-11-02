#include <stdio.h>
#include <string.h>
char sgets(char *s, int len)
{
    char *ss;
    int i = 0;
    ss = fgets(s, len, stdin);
    if (ss)
    {
        while (s[i] != '\n' && s[i] != '\0')
            i++;
        if (s[i] == '\n')
            s[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ss;
}
int main()
{
    int len = 10;
    char *sy;
    char *s = (char *)"abcdefghig";
    sy = sgets(s, len);
    printf("%s", sy);
}