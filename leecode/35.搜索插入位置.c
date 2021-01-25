/*
 * @lc app=leetcode.cn id=35 lang=c
 *
 * [35] 搜索插入位置
 */

// @lc code=start

int erfen(int *nums, int numsSize, int target)
{
    int wei = rand() % (numsSize) + 1; //1_3
    while (1)
    {
        if (target > nums[wei - 1] && target <= nums[wei])
        {
            return wei;
        }
        wei = rand() % (numsSize) + 1;
    }
    return 0;
}
int searchInsert(int *nums, int numsSize, int target)
{
    if (numsSize == 0)
        return 0;
    else if (numsSize == 1)
    {
        if (target <= nums[0])
            return 0;
        else
            return 1;
    }

    if (target <= nums[0])
        return 0;
    else if (target > nums[numsSize - 1])
        return numsSize;
    else
    {
        int sum = erfen(nums, numsSize, target);
        return sum;
    }
}
// @lc code=end
