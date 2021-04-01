#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    double x, y, z, sum;

    char s[100] = {0};
    scanf("%s", s);
    int len = strlen(s);
    c = 0;
    int count = 0;
    int f[100] = {0};
    int d[100] = {0};
    char *m=NULL;
    while ((m=strchr(&s[c], '+')) != NULL || (m=strchr(&s[c], '-') )!= NULL ||(m= strchr(&s[c], '/')) != NULL || (m=strchr(&s[c], '*')) != NULL||(m=strchr(&s[c],'='))!=NULL)
    {
        
        c=(int)(m-&s[c])+1;f[count++] = c; //存符号下标
        ;
    }

    int j = 0;
    for (int i = 0; i < len; i++)
    {
        d[j] = atoi(&s[i]); //存数
        i = f[j++];
    }
    for (int i = 0; i < count; i++)
    {
        if (s[f[i]] == '+')
            d[i + 1] += d[i];
        if (s[f[i]] == '-')
            d[i + 1] -= d[i];
        if (s[f[i]] == '*')
            d[i + 1] *= d[i];
        if (s[f[i]] == '/')
            d[i + 1] /= d[i];
    }
    printf("%d",d[count]);
}