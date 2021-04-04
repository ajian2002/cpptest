/*
 * @lc app=leetcode.cn id=437 lang=c
 *
 * [437] 路径总和 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dod(struct TreeNode *node, int count) //node节点开始所有可能性
{
    int s = 0;
    if (0 == count)
        s++;
    //printf("nodeval  %d   count   %d\n", node->val, count);
    if (node->left)
        s += dod(node->left, count - node->left->val);
    if (node->right)
        s += dod(node->right, count - node->right->val);
    return s;
}
void per(struct TreeNode *node, int sum,int *s) //前序遍历
{
    //int count = 0;
    
    
    
    //printf("val  %d  \n", node->val);
    (*s) += dod(node, sum - node->val);

    if (node->left)
    {
        per(node->left, sum,s);
    }
    if (node->right)
    {
        per(node->right, sum,s);
    }
    // if (node->left == NULL && node->right == NULL)
    //     return ;
    //return count;
    //step += dod(node, sum - node->val);

    //return step;
}
int pathSum(struct TreeNode *root, int sum)
{
    int count = sum;
    int step = 0;
    if (!root)
        return step;
    per(root, sum,&step);
    //step += dod(root, sum - root->val);
    //printf("step = %d\n",step);
    return step;
}
// @lc code=end
