/*
 * @lc app=leetcode.cn id=114 lang=c
 *
 * [114] 二叉树展开为链表
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

struct TreeNode *te(struct TreeNode *node)
{
    if (node == NULL)
        return NULL;
    if (node->left == NULL && node->right == NULL)
    {
        return node;
    }
    else if (node->left == NULL && node->right != NULL)
    {
        return te(node->right);
    }
    else if (node->right == NULL && node->left != NULL)
    {
        node->right = node->left;
        node->left = NULL;
        return te(node->right);
    }
    else
    {
        struct TreeNode *temp = node->right;

        node->right = node->left;
        node->left = NULL;

        struct TreeNode *last =
            te(node->right);

        last->right = temp;
        return te(temp);
    }
}
void flatten(struct TreeNode *root)
{
    te(root);
}
// @lc code=end
