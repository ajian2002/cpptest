/*
 * @lc app=leetcode.cn id=162 lang=c
 *
 * [162] 寻找峰值
 */

// @lc code=start
int erfen(int *nums, int numsSize)
{
    int wei = rand() % (numsSize - 1) + 1;
    while (1)
    {
        if (nums[wei] > nums[wei - 1] && nums[wei] > nums[wei + 1])
        {
            return wei;
        }
        wei = rand() % (numsSize - 1) + 1;
    }
    return 0;
}

int findPeakElement(int *nums, int numsSize)
{
    int sum = 0;
    if (numsSize == 1)
        return 0;
    else if (nums[0] > nums[1])
        return 0;
    else if (nums[numsSize - 1] > nums[numsSize - 2])
        return numsSize - 1;
    else
    {
        srand((unsigned int)time(NULL));
        sum = erfen(nums, numsSize);
    }
    return sum;
}

// @lc code=end
