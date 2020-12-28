/*
 * @lc app=leetcode.cn id=86 lang=c
 *
 * [86] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *partition(struct ListNode *head, int x)
{
    if (head == NULL)
        return NULL;
    struct ListNode *temp = head;
    struct ListNode *back = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *NODE = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *left = back;
    left->next = NULL;
    //left->next->next = (struct ListNode *)malloc(sizeof(struct List))
    struct ListNode *right = NODE;
    right->next = NULL;
    while (temp != NULL)
    {
        if (temp->val < x)
        {

            left->next = (struct ListNode *)malloc(sizeof(struct ListNode));

            left = left->next;

            left->val = temp->val;

            left->next = NULL;
        }
        else
        {
            right->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            right = right->next;
            right->val = temp->val;
            right->next = NULL;
        }
        temp = temp->next;
    }

    left->next = NODE->next;
    free(NODE);
    temp = back->next;
    free(back);
    return temp;
}

// @lc code=end
