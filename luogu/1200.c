#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s1[8];
    char s2[8];
    memset(s1, 'A', 6);
    s1[6] = '\0';
    memset(s2, 'A', 6);
    s2[6] = '\0';
    scanf("%s", s1);

    if (getchar() == '\r')
        getchar();
    scanf("%s", s2);
    int sum1 = 1, sum2 = 1;
    for (int i = 0; i < 6; i++)
    {
        if (s1[i] == '\0')
            break;
        sum1 *= s1[i] + 1 - 'A';
    }
    sum1 = sum1 % 47;
    for (int i = 0; i < 6; i++)
    {

        if (s2[i] == '\0')
            break;
        sum2 *= s2[i] + 1 - 'A';
    }

    sum2 = sum2 % 47;
    if (sum1 == sum2)
        printf("GO");
    else
        printf("STAY");
}