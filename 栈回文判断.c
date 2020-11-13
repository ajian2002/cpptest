#include <stdio.h>
#include <string.h>
#define SS "abcdcbsda"
int main()
{
    char s[20] = SS;
    char d[11] = {0};
    //strcpy(s, SS);
    int len = strlen(s);
    int mid = len / 2 - 1;
    int top = 0;
    for (int i = 0; i <= mid; i++)
    {
        d[i] = s[i];
        top = mid;
    }
    int next;
    if (len % 2 == 0)
        next = mid + 1;
    else
        next = mid + 2;
    for (; next < len; next++)
    {
        if (d[top] == s[next])
        {
            if (top == 0)
                return 0;

            top--;
        }
        else
        {
            printf("-1");
            return 0;
        }
    }
    printf("yes");
    return 0;
}