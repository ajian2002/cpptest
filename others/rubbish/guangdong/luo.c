#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    char s[n];
    scanf("%s", s);
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == s[i + 1] && s[i + 1] != s[i])
        {
            sum++;
            s[i] = s[i + 1];
        }
    }
    printf("%d", sum);
}