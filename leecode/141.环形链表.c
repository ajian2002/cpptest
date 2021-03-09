/*
 * @lc app=leetcode.cn id=141 lang=c
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
    if (head == NULL)
        return false;
    while (head)
    {
        if ((head->val) == 1587664)
        {
            return true;
        }
        head->val = 1587664;
        head = head->next;
    }

    return false;
}
// @lc code=end
