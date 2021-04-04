/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if (!l1 && l2)
    {
        return l2;
    }
    else if (!l2 && l1)
    {
        return l1;
    }
    else if (!l1 && !l2)
    {
        return NULL;
    }
    struct ListNode *left = l1;
    struct ListNode *right = l2;
    struct ListNode *head = right;
    if (left->val <= right->val)
    {
        head = left;
        left = left->next;
    }
    else
    {
        right = right->next;
    }
    struct ListNode *temp = head;
    while (left || right)
    {
        if (!left)
        {
            temp->next = right;
            return head;
        }
        else if (!right)
        {
            temp->next = left;
            return head;
        }
        else
        {
            if (left->val <= right->val)
            {

                temp->next = left;
                left = left->next;
                temp = temp->next;
            }
            else
            {
                temp->next = right;
                right = right->next;
                temp = temp->next;
            }
        }
    }
    return head;
}
// @lc code=end
