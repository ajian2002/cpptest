#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include <stdarg.h> //使用可变参数需要的头文件
#include <stdio.h>

char *min(int count, ...)
{
    va_list ap;           //1）定义一个可变参数，这个地方其实是一个指针，用于访问可变参数中的参数列表
    va_start(ap, count);  //2）初始化可变参数，并把刚定义的指针指向第一个参数。
    char *maximum = NULL; //假设这都是正整数求最大值，如果不是，就可以把maximum设为最大的负数
    int i;
    char *temp = NULL;
    for (i = 0; i < count; i++)
    {

        temp = va_arg(ap, char *); //从可变参数列表指针的当前位置获取一个int型参数，并把指针指向下一个参数。
        if (temp == NULL)
            continue;
        if (i == 0 || maximum == NULL)
            maximum = temp;
        if (temp != NULL && maximum > temp)
            maximum = temp;
    }
    va_end(ap); //结束
    return maximum;
}

int main()
{
    int a, b, c;
    double x, y, z, sum;

    char s[100] = {0};
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] == '+' || s[i] == '*' || s[i] == '-' || s[i] == '/') || s[i] == '=')
            continue;
        else
            goto wwc;
    }

    c = 0;
    int count = 0;
    int f[100] = {0};
    int d[100] = {0};
    char *m = NULL, *n = NULL, *p = NULL, *q = NULL, *w = NULL;
    m = strchr(&s[c], '+');
    n = strchr(&s[c], '-');
    p = strchr(&s[c], '/');
    q = strchr(&s[c], '*');
    w = strchr(&s[c], '=');
    while (m || n || p || q || w)
    {

        m = min(5, m, n, p, q, w);
        c = (int)(m - &s[0]);
        f[count++] = c; //存符号下标
        c++;
        if (s[c] == '-')
            c++;
        m = NULL;
        n = NULL;
        p = NULL;
        q = NULL;
        w = NULL;
        m = strchr(&s[c], '+');
        n = strchr(&s[c], '-');
        p = strchr(&s[c], '/');
        q = strchr(&s[c], '*');
        w = strchr(&s[c], '=');
    }
    int j = 0;
    for (int i = 0; i < len && j < count; i++)
    {
        d[j] = atoi(&s[i]); //存数
        i = f[j++];
    }

    // for (int i = 0; i < count; i++)
    // {
    //     printf("f%d :%d\n ", i, f[i]);
    //     printf("d%d :%d\n ", i, d[i]);
    // }
    for (int i = 0; i < count; i++)
    {
        if (s[f[i]] == '+')
            d[i + 1] += d[i];
        if (s[f[i]] == '-')
            d[i + 1] = d[i] - d[i + 1];
        if (s[f[i]] == '*')
            d[i + 1] *= d[i];
        if (s[f[i]] == '/')
            if (d[i + 1] != 0)
                d[i + 1] = d[i] / d[i + 1];
            else
            {
            wwc:
                printf("ERROR");
                exit(0);
            }
    }
    // for (int i = 0; i < count; i++)
    // {
    //     printf("f%d :%d\n ", i, f[i]);
    //     printf("d%d :%d\n ", i, d[i]);
    // }
    printf("%d", d[count - 1]);
}
