/*
 * @lc app=leetcode.cn id=374 lang=c
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n)
{
    srand((unsigned int)time(NULL));
    int left = 0;
    int right = n;
    long count = (right - left) / 2;
    int compare = guess(count);
    while (compare != 0)
    {

        if (compare > 0) //count -n
        {
            left = count + 1;
        }
        else //0-count
        {
            right = count - 1;
        }
        count = (right - left) / 2 + left;
        compare = guess(count);
    }
    return (int)count;
}
// @lc code=end
