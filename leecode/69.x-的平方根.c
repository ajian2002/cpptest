/*
 * @lc app=leetcode.cn id=69 lang=c
 *
 * [69] x 的平方根
 */

// @lc code=start

int mySqrt(int x)
{
    long l = 0, r = x;
    while (l <= r)
    {
        long long mid = (r - l) / 2 + l;
        if (mid * mid <= x && (mid + 1) * (mid + 1) > x)
            return mid;
        else if (mid * mid < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return 0;
}
// @lc code=end
