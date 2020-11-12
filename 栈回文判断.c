#include <stdio.h>
#include <string.h>
#define SS "abcdedcba"
int main()
{
    char s[20], d[11];
    strcpy(s, SS);
    int len = strlen(s);
    int mid = len / 2 - 1;
    int top = 0;
    for (int i = 0; i <= mid; i++)
    {
        d[i] = s[i];
        top++;
    }
    int next;
    if (len % 2 == 0)
        next = mid + 1;
    else
        next = mid + 2;
    for (; next < len; next++)
        if (d[top--] == s[next])
            continue;
        else
        {
            printf("-1");
            return 0;
        }
    printf("yes");
    return 0;
}