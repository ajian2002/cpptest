/*
 * @lc app=leetcode.cn id=116 lang=c
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */
void help(struct Node *node)
{
    if (node == NULL || node->left == NULL)
        return;
    else
    {

        struct Node *ltemp = node->left;
        struct Node *rtemp = node->right;
        ltemp->next = rtemp;
        while (ltemp->right != NULL && rtemp != NULL)
        {
            ltemp->right->next = rtemp->left;
            ltemp = ltemp->right;
            rtemp = rtemp->left;
        }
    }
    help(node->left);
    help(node->right);
}
struct Node *connect(struct Node *root)
{
    //left->right----right->left
    help(root);
    return root;
}
// @lc code=end
