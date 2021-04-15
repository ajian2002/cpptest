/*
 * @lc app=leetcode.cn id=226 lang=c
 *
 * [226] 翻转二叉树
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

void reserve(struct TreeNode *node)
{
    if (node == NULL)
        return;
    struct TreeNode *temp = node->left;
    node->left = node->right;
    node->right = temp;

    reserve(node->left);
    reserve(node->right);
}
struct TreeNode *invertTree(struct TreeNode *root)
{
    reserve(root);
    return root;
}
// @lc code=end
