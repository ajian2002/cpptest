/*
 * @lc app=leetcode.cn id=203 lang=c
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *removeElements(struct ListNode *head, int val)
{
    struct ListNode *prev = head;
    if (head == NULL)
        return NULL;
    struct ListNode *nn = head->next;
    struct ListNode *temp = head;
    struct ListNode *first = head;

    while (nn != NULL)
    {
        if (first->val == val)
        {
            prev = prev->next;
            first = first->next;
            temp = first;
            nn = nn->next;
        }
        else if (temp->val == val && temp != prev)
        {
            prev->next = nn;
            temp = temp->next;
            nn = nn->next;
        }
        else
        {
            if (prev == temp)
            {
                temp = temp->next;
                nn = nn->next;
            }
            else
            {
                prev = prev->next;
                temp = temp->next;
                nn = nn->next;
            }
        }
    }
    if (temp->val == val)
    {
        if (temp == prev && first == prev)
        {
            first = NULL;
        }
        else
        {
            prev->next = NULL;
        }
    }
    return first;
}

// @lc code=end
