/*
 * @lc app=leetcode.cn id=34 lang=c
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int a = 0;
    int left = 0;
    int right = numsSize - 1;
    *returnSize =2;
    int mid;
    int j=-1;
    if (numsSize==0||(numsSize==1&&nums[0]!=target))
    {
            nums=(int *)realloc(nums,sizeof(int)*2);
            nums[0]=nums[1]=-1;
            return nums;
    }
    
    while (left <= right)
    {
        j=-1;
        mid = (right - left + 1) / 2 + left;
        if (nums[mid] == target)
        {    j=mid;
        break;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
    }
    if(j==-1)
    {
        nums[0]=nums[1]=-1;
    }
    else
    {
        if(numsSize==1&&nums[0]==target)
        {    
            nums=(int *)realloc(nums,sizeof(int)*2);
            nums[0]=nums[1]=0;
            return nums;
        }
        int m=j;
        while(j>0&&nums[j-1]==nums[j])
        j--;
        nums[0]=j;
        while(m<numsSize-1&&nums[m+1]==nums[m])
        m++;
        nums[1]=m;   
        
    }
    return nums;
}
// @lc code=end

