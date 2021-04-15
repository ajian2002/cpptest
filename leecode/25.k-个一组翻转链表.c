/*
 * @lc app=leetcode.cn id=25 lang=c
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *renserve(struct ListNode *a, struct ListNode *b)
{
    struct ListNode *prev = NULL;
    struct ListNode *next = a->next;
    struct ListNode *now = a;

    while (next != b)
    {
        now->next = prev;
        prev = now;
        now = next;
        next = next->next;
    }
    now->next = prev;
    a->next = next;
    return now;
}
struct ListNode *help(struct ListNode *node, int k)
{
    struct ListNode *a = node;
    struct ListNode *b = node;
    for (int i = 0; i < k; i++)
    {
        if (b == NULL)
            return node;
        b = b->next;
    }
    struct ListNode *newhead = renserve(a, b);
    a->next = help(b, k);
    return newhead;
}
struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
    return help(head, k);
}
// @lc code=end
