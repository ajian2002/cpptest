/*
 * @lc app=leetcode.cn id=704 lang=c
 *
 * [704] 二分查找
 */

// @lc code=start

int search(int *nums, int numsSize, int target)
{
    int a = 0;
    int left = 0;
    int right = numsSize - 1;
    while (left <= right)
    {
        int mid = (right - left + 1) / 2 + left;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
    }
    return -1;
}

// @lc code=end
