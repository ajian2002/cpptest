/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start

bool isValid(char *s)
{
    int len = strlen(s);
    bool ok = true;
    char *a = (char *)malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            a[j++] = s[i];
        }
        else if (j > 0)
        {
            if (s[i] == ']')
            {
                if (a[j - 1] == '[')
                {
                    j--;
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            else if (s[i] == '}')
            {
                if (a[j - 1] == '{')
                {
                    j--;
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            else if (s[i] == ')')
            {
                if (a[j - 1] == '(')
                {
                    j--;
                }
                else
                {
                    ok = false;
                    break;
                }
            }
        }
        else
        {
            ok = false;
            break;
        }
    }
    if (j != 0)
        ok = false;

    free(a);
    return ok;
}
// @lc code=end
