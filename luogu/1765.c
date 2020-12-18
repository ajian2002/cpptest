#include <stdio.h>
#include <string.h>
int to(char *c, int len)
{
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (c[i] == ' ')
            count++;
        if (c[i] == 'a' || c[i] == 'd' || c[i] == 'g' || c[i] == 'j' || c[i] == 'm' || c[i] == 'p' || c[i] == 't' || c[i] == 'w')
            count++;
        if (c[i] == 'a' + 1 || c[i] == 'd' + 1 || c[i] == 'g' + 1 || c[i] == 'j' + 1 || c[i] == 'm' + 1 || c[i] == 'p' + 1 || c[i] == 't' + 1 || c[i] == 'w' + 1)
            count += 2;
        if (c[i] == 'a' + 2 || c[i] == 'd' + 2 || c[i] == 'g' + 2 || c[i] == 'j' + 2 || c[i] == 'm' + 2 || c[i] == 'p' + 2 || c[i] == 't' + 2 || c[i] == 'w' + 2)
            count += 3;
        if (c[i] == 's' || c[i] == 'z')
            count += 4;
        
    }
    return count;
}
int main()
{
    char s[300];
    fgets(s, 210, stdin);
    int len = strlen(s) - 1;
    int sum = to(s, len);
    printf("%d\n", sum);
}