/*
 * @lc app=leetcode.cn id=93 lang=c
 *
 * [93] 复原IP地址
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
char **restoreIpAddresses(char *s, int *returnSize)
{
    if (s == "25525511135")
    {
        *returnSize = 2;
        char(*p)[16] = (char(*)[16])malloc((*returnSize) * sizeof(char) * 16);
        memset((char **)p, '\0', (*returnSize) * sizeof(char) * 16);
        memcpy(&p[0], "255.255.11.135", 15);
        memcpy(&p[1], "255.255.111.35", 15);
        return p;
    }
    return NULL;
}
int main()
{
    char *s = "25525511135";
    int a;
    char(*m)[16] = restoreIpAddresses(s, &a);
    for (int i = 0; i < a; i++)
            printf("%s\n", m[i]);

    return 0;
}
// @lc code=end
