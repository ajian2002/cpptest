/*
 * @lc app=leetcode.cn id=1009 lang=c
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int bitwiseComplement(int N)
{
    char *s = (char *)malloc(sizeof(char) * 40);
    int len = 0;
    int temp = N;
    if (temp == 0)
    {
        return 1;
    }
    while (temp != 0)
    {
        s[len++] = temp % 2 + '0';
        temp /= 2;
    }
    s[len] = '\0';
    int le = 0, ri = len - 1;
    /*while (le < ri)
    {
        char t = s[ri];
        s[ri--] = s[le];
        s[le++] = t;
    }*/
    //printf("%s\n", s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '1')
            s[i] = '0';
        else
            s[i] = '1';
    }
    //printf("%s\n", s);
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += pow(2, i) * (s[i] - '0');
    }
    //printf("%d\n", sum);
    free(s);
    return sum;
}

// @lc code=end
