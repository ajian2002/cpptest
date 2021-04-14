/*
 * @lc app=leetcode.cn id=28 lang=c
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.59%)
 * Likes:    651
 * Dislikes: 0
 * Total Accepted:    272.4K
 * Total Submissions: 688K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */

// @lc code=start

char *KMP(char *s1, char *s2)
{
    //strstr(s1,s2);
    int M = strlen(s1);
    int N = strlen(s2);
    int i = 0, j = 0;
    //temp[N][256]
    int **temp = (int **)malloc(sizeof(int *) * (N));
    for (i = 0; i < N; i++)
    {
        temp[i] = (int *)malloc(256 * sizeof(int));
        memset(temp[i], 0, 256 * sizeof(int));
    }
    temp[0][(int)s2[0]] = 1;
    int x = 0;
    int c = 0;

    for (j = 1; j < N; j++)
    {
        for (c = 0; c < 256; c++)
        {
            // if (s2[j] == c)
            //     temp[j][c] = j + 1;
            // else
            //     temp[j][c] = temp[x][c];
            temp[j][c] = temp[x][c];
            temp[j][(int)s2[j]] = j + 1;
        }
        x = temp[x][(int)s2[j]];
        //printf("c:%d\n", c);
    }

    //search
    j = 0;
    for (i = 0; i < M; i++)
    {
        j = temp[j][(int)s1[i]];
        if (j == N)
        {
            //printf("%d  %s\n", i - N + 1, &s1[i - N + 1]);
            return &s1[i - N + 1];
        }
    }

    return NULL;
}
int strStr(char *haystack, char *needle)
{
    if (strlen(needle) == 0)
    {
        return 0;
    }
    char *temp = NULL;
    temp = KMP(haystack, needle);
    if (temp == NULL)
    {
        return -1;
    }
    else
    {
        return (int)(temp - haystack);
    }
}

// @lc code=end
