#include <stdio.h>
#include <string.h>
int main()
{
    char s[500];
    scanf("%s", s);
    int len = strlen(s);
    int b = 0, g = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'b' || s[i + 1] == 'o' || s[i + 2] == 'y')
            b++;
        if (s[i] == 'g' || s[i + 1] == 'i' || s[i + 2] == 'r' || s[i + 3] == 'l')
            g++;
    }
    printf("%d\n%d", b, g);
}