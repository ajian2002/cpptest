#include <stdio.h>
#include <string.h>
int number(char s[], int x[])
{ //a both another first second third
    int i = 5;
    if (strstr(s, " a ") != NULL)
    {

        if (i > -1)
            x[i--] = 1;
        else
            return 0;
    }
    if (strstr(s, " both ") != NULL)
    {

        if (i > -1)
            x[i--] = 1;
        else
            return 0;
    }
    if (strstr(s, " another ") != NULL)
    {

        if (i > -1)
            x[i--] = 1;
        else
            return 0;
    }
    if (strstr(s, " first ") != NULL)
    {
        if (i > -1)
            x[i--] = 1;
        else
            return 0;
    }
    if (strstr(s, " second ") != NULL)
    {
        if (i > -1)
            x[i--] = 1;
        else
            return 0;
    }
    if (strstr(s, " third ") != NULL)
    {

        if (i > -1)
            x[i--] = 1;
        else
            return 0;
    }
    if (strstr(s, " one ") != NULL)
    {
        if (i > -1)
            x[i--] = 1;
        else
            return 0;
    }
    if (strstr(s, " two ") != NULL)
    {
        if (i > -1)
            x[i--] = 4;
        else
            return 0;
    }
    if (strstr(s, " three ") != NULL)
    {

        if (i > -1)
            x[i--] = 9;
        else
            return 0;
    }
    if (strstr(s, " four ") != NULL)
    {
        if (i > -1)
            x[i--] = 16;
        else
            return 0;
    }
    if (strstr(s, " five ") != NULL)
    {
        if (i > -1)
            x[i--] = 25;
        else
            return 0;
    }
    if (strstr(s, " six ") != NULL)
    {

        if (i > -1)
            x[i--] = 36;
        else
            return 0;
    }
    if (strstr(s, " seven ") != NULL)
    {

        if (i > -1)
            x[i--] = 49;
        else
            return 0;
    }
    if (strstr(s, " eight ") != NULL)
    {
        if (i > -1)
            x[i--] = 64;
        else
            return 0;
    }
    if (strstr(s, " nine ") != NULL)
    {
        if (i > -1)
            x[i--] = 81;
        else
            return 0;
    }
    if (strstr(s, " ten ") != NULL)
    {

        if (i > -1)
            x[i--] = 0;
        else
            return 0;
    }
    if (strstr(s, " eleven ") != NULL)
    {

        if (i > -1)
            x[i--] = 21;
        else
            return 0;
    }
    if (strstr(s, " twelve ") != NULL)
    {

        if (i > -1)
            x[i--] = 44;
        else
            return 0;
    }
    if (strstr(s, " thirteen ") != NULL)
    {

        if (i > -1)
            x[i--] = 69;
        else
            return 0;
    }
    if (strstr(s, " fourteen ") != NULL)
    {

        if (i > -1)
            x[i--] = 96;
        else
            return 0;
    }
    if (strstr(s, " fifteen ") != NULL)
    {

        if (i > -1)
            x[i--] = 25;
        else
            return 0;
    }
    if (strstr(s, " sixteen ") != NULL)
    {
        if (i > -1)
            x[i--] = 56;
        else
            return 0;
    }
    if (strstr(s, " seventeen ") != NULL)
    {
        if (i > -1)
            x[i--] = 89;
        else
            return 0;
    }
    if (strstr(s, " eighteen ") != NULL)
    {

        if (i > -1)
            x[i--] = 24;
        else
            return 0;
    }
    if (strstr(s, " nineteen ") != NULL)
    {
        if (i > -1)
            x[i--] = 61;
        else
            return 0;
    }
    if (strstr(s, " twenty ") != NULL)
    {

        if (i > -1)
            x[i--] = 0;
        else
            return 0;
    }
    return 0;
}
void qqsort(int *p, int l, int r)
{
    int j = l, k = r;
    if (l < r)
    {
        int temp = p[l];
        while (l != r)
        {
            while (l < r && p[r] >= temp)
                r--;
            // if (l != r)
            p[l] = p[r];
            while (l < r && p[l] <= temp)
                l++;
            //if (l != r)
            p[r] = p[l];
        }
        if (r == l)
            p[r] = temp;

        qqsort(p, r + 1, k);
        qqsort(p, j, r - 1);
    }
}
int main()
{
    char s[50];
    char c;
    c = getchar();
    int i = 1;
    s[0] = ' ';
    while (c != '.')
    {
        s[i++] = c;
        c = getchar();
    }
    s[i] = ' ';
    s[i + 1] = '\0';
    int x[6] = {0};
    number(s, x);
    qqsort(x, 0, 5);
    int thiss = 0;
    int sum = 0;
    for (i = 0; i < 6; i++)
        if (x[i] == 0)
            sum++;
    if (sum == 6)
    {
        printf("0");
        return 0;
    }
    for (i = 0; i < 6; i++)
    {
        if (x[i] > 0)
        {
            if (x[i] < 10 && thiss == 0)
            {
                thiss = 1;
                printf("%d", x[i]);
            }
            else if (x[i] < 10 && thiss == 1)
            {
                printf("0%d", x[i]);
            }
            else
            {
                printf("%d", x[i]);
            }
        }
    }
}