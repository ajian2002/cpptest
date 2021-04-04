/*
 * @lc app=leetcode.cn id=33 lang=c
 *
 * [33] 搜索旋转排序数组
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
        return 0;

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
                return wei + 1;
            }
            else if (nums[wei] < nums[wei + 1])
                return wei;
        }
        wei = rand() % (numsSize - 2) + 1;
    }
    return 0;
}

int findMin(int *nums, int numsSize)
{
    int sum = 0; //1 2
    if (numsSize == 1)
        return 0;
    if (nums[numsSize - 1] < nums[numsSize - 2])
        return numsSize - 1;
    else
    {
        srand((unsigned int)time(NULL));
        sum = erfen(nums, numsSize);
    }
    return sum;
}

int search1(int *nums, int left, int right, int target)
{
    int a = 0;
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

int search(int *nums, int numsSize, int target)
{
    int mi = findMin(nums, numsSize);
    //printf("%d", mi);
    int left = 0;
    int right = numsSize - 1;
    int ll = -1;
    int rr = -1;
    if (mi == 0)
    {
        //0--size-1
        ;
    }
    else
    {
        if (nums[0] > target)
        {
            left = mi;
            //mi-----size-1
        }
        else
        {
            //two
            //0--mi    mi+1--size-1
            ll = mi ;
            rr = right;
            left = 0;
            right = mi-1;
        }
    }
    int t = -1;
    if (ll == -1 && rr == -1)
    {
        t = search1(nums, left, right, target);
    }
    else
    {
        t = search1(nums, left, right, target);
        if (t == -1)
            t = search1(nums, ll, rr, target);
    }
    return t;
}

// @lc code=end
