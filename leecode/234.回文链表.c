/*
 * @lc app=leetcode.cn id=234 lang=c
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool isPalindrome(struct ListNode *head)
{
    int len = 0;
    struct ListNode *temp = head;
    struct ListNode *right = head;
    int sl = 0;
    int sr = 0;
    int sum = 0;
    while (temp != NULL)
    {
        len++;
        sum += temp->val;
        temp = temp->next;
    }
    if (len == 0 || len == 1)
        return true;

    if (len % 2 == 0)
    {
        for (int i = 0; i < len / 2; i++)
        {
            sl += right->val;
            right = right->next;
        }
    }
    else
    {
        int x = len / 2 + 1;
        for (int i = 0; i < x; i++)
        {
            if (i < x - 1)
                sl += right->val;
            right = right->next;
        }
    }
    temp = head;
    int max = right->val + temp->val;
    if (2 * sl != sum)
        return false;
    if (len == 2 || len == 3)
    {
        if (right->val == temp->val)
            return true;
        else
            return false;
    }
    /*
    while (right != NULL)
    {

        if (right->val + temp->val == max)
        {
            right = right->next;
            temp = temp->next;
        }
        else
            return false;
    }
    return true;
    */
}

// @lc code=end
