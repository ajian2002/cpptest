/*
 * @lc app=leetcode.cn id=961 lang=c
 *
 * [961] 重复 N 次的元素
 */

// @lc code=start


int repeatedNTimes(int* A, int ASize){
    
    for(int i = 0; i <50;i++)
{    int a=rand()%ASize;

    int b=rand()%ASize;
    if(a!=b&&A[a]==A[b])
    {
        return A[a];
    }
}
return A[0];
}
// @lc code=end

