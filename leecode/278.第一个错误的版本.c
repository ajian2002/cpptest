/*
 * @lc app=leetcode.cn id=278 lang=c
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n)
{

    if (isBadVersion(1))
        return 1;
    
    if (n < 2)
    {
        if (n <= 0)
        {

            return -1;
        }
        else if (n == 1)
        {
            if (isBadVersion(1))
                return 1;
            else
                return -1;
        }
    }

    int l = 2;
    int r = n;
    int mid = (r - l) / 2 + l;
    while (l <= r)
    {
        if (isBadVersion(mid))
        {
            if (!(isBadVersion(mid - 1)))
            {
                return mid;
            }
            else
            {
                r = mid;
            }
        }
        else
        {
            l = mid + 1;
        }
        mid = (r - l) / 2 + l;
    }
    return -1;
}
//@lc code=end
