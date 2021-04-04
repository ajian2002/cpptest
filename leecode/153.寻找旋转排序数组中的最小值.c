/*
 * @lc app=leetcode.cn id=153 lang=c
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
int erfen(int *nums, int numsSize)
{
    int i = 0;
    for (i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] > nums[i + 1])
            break;
    }
    if (i == numsSize - 1)
        return nums[0];

    int wei = rand() % (numsSize - 2) + 1;
    while (1)
    {
        if (nums[wei] > nums[wei - 1] && nums[wei] < nums[wei + 1])
        {
            ;
        }
        else
        {
            if (nums[wei] > nums[wei - 1])
            {
                return nums[wei + 1];
            }
            else if (nums[wei] < nums[wei + 1])
                return nums[wei];
        }
        wei = rand() % (numsSize - 2) + 1;
    }
    return 0;
}

int findMin(int *nums, int numsSize)
{
    int sum = 0; //1 2
    if (numsSize == 1)
        return nums[0];
    if (nums[numsSize - 1] < nums[numsSize - 2])
        return nums[numsSize - 1];
    else
    {
        srand((unsigned int)time(NULL));
        sum = erfen(nums, numsSize);
    }
    return sum;
}
// @lc code=end
