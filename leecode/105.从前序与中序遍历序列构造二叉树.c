/*
 * @lc app=leetcode.cn id=105 lang=c
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
    if (inorderSize != preorderSize || inorderSize == 0)
        return NULL;
    int sum = preorderSize;

    struct TreeNode *head =NULL;
    // head->val = preorder[0];
    // head->left = NULL;
    // head->right = NULL;
    /*
    int i = 0;
    int midval = preorder[0];
    while (inorder[i] != midval)
    {
        i++;
    }
    int leftnum = i;
    int rightnum = sum - 1 - leftnum;

    creat_left(head, inorder, 0, i - 1);
    creat_right(head, inorder, i + 1, sum - 1);
    */
    int *old = (int *)malloc(sizeof(int) * sum);
    memset(old, 0, sizeof(int) * sum);
    struct TreeNode *node[sum];
    for (int i = 0; i < sum; i++)
    {
        node[i] = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        node[i]->val = inorder[i];
        node[i]->left = NULL;
        node[i]->right = NULL;
    }

    for (int i = 0; i < sum; i++)
    {
        //mark
        int wei;int fakewei;
        for (int j = 0; j < sum; j++)
        {

            if (inorder[j] == preorder[i])
            {
                if(i==0)
                head=node[j];
            
            
                old[j] = 1;
                wei=j;
                break;
            }
        }

        int ll, rr;
        //寻找lr与rl
        ll = 0;
        rr = 0;
        for (int j = 0; j < wei; j++)
        {
            if (old[j] == 1)
                ll = 0;
                else
                ll++;
        }
        for (int j = wei + 1; j < sum; j++)
        {

            
            if (old[j] != 1)
            rr++;
            else break;
        }
        
        //printf("%d:ll %d  rr %d\n",inorder[wei], ll, rr);

        if(ll>0)
        {
            for (int j = 0; j < sum; j++)
            {
                if (inorder[j] == preorder[i+1])
                {
                    fakewei = j;
                    break;
                }
            }
            node[wei]->left=node[fakewei];
        }
        if(rr>0)
        {
            for (int j = 0; j < sum; j++)
            {
                if (inorder[j] == preorder[i + ll+1])
                {
                    fakewei = j;
                    break;
                }
            }
            node[wei]->right=node[fakewei];
        }
        //if(node[wei-1]->val==preorder[0])


        
    }

    free(old);
    return head;
}

// @lc code=end
