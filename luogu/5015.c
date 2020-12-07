#include <stdio.h>
#include <string.h>
int main()
{
    char s[10000];
    //    scanf("%s", s);
    int len, sum;
    sum = 0;
    char c = getchar();
    while (c != '\n')
    {
        if (c != ' ')
            sum++;
        c = getchar();
    }
    printf("%d", sum);
}