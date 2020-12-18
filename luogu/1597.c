#include <stdio.h>
#include <string.h>
int main()
{
    char s[10000];
    scanf("%s", s);
    int len = strlen(s);
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'a' && s[i + 1] == ':' && s[i + 2] == '=' && s[i + 4] == ';')
        {
            if (s[i + 3] >= '0' && s[i + 3] <= '9')
                a = s[i + 3] - '0';
            else
            {
                if (s[i + 3] == 'b')
                    a = b;
                else if (s[i + 3] == 'c')
                    a = c;
            }
        }
        if (s[i] == 'b' && s[i + 1] == ':' && s[i + 2] == '=' && s[i + 4] == ';')
        {
            if (s[i + 3] >= '0' && s[i + 3] <= '9')
                b = s[i + 3] - '0';
            else
            {
                if (s[i + 3] == 'a')
                    b = a;
                else if (s[i + 3] == 'c')
                    b = c;
            }
        }
        if (s[i] == 'c' && s[i + 1] == ':' && s[i + 2] == '=' && s[i + 4] == ';')
        {
            if (s[i + 3] >= '0' && s[i + 3] <= '9')
                c = s[i + 3] - '0';
            else
            {
                if (s[i + 3] == 'b')
                    c = b;
                else if (s[i + 3] == 'a')
                    c = a;
            }
        }
    }
    printf("%d %d %d", a, b, c);
}