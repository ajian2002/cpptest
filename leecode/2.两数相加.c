/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (39.17%)
 * Likes:    5426
 * Dislikes: 0
 * Total Accepted:    662.1K
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head = NULL;
    struct ListNode *temp1 = l1;
    struct ListNode *temp2 = l2;
    struct ListNode *temp11 = l1;
    struct ListNode *temp22 = l2;
    //struct ListNode *s = NULL;
    int dirr = 0;
    while (l2 != NULL && l1 != NULL)
    {

        l1->val = l1->val + dirr + l2->val;
        l2->val = l1->val;
        if (l1->val > 9)
        {
            dirr = (l1->val) / 10;
            l1->val = (l1->val) % 10;
            l2->val = l1->val;
        }
        else
        {
            dirr = 0;
        }
        temp11 = l1;
        temp22 = l2;
        l1 = l1->next;
        l2 = l2->next;
    } //到达结尾
    if (l2 == NULL && l1 != NULL)
    {
        head = l1;
        temp22->next = head;
        l1->val = l1->val + dirr;
        dirr = 0;
    }
    if (l2 != NULL && l1 == NULL)
    {
        head = l2;
        temp11->next = head;
        temp1 = temp2;
        l2->val = l2->val + dirr;
        dirr = 0;
    }
    if (l2 == NULL && l1 == NULL)
    {
        if (temp11->val < 10 && dirr == 0)
        {
            return temp1;
        }
        head = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp11->next = head;
        head->val = dirr;
        head->next = NULL;
        dirr = 0;
    }
    //开始递进
    while (1)
    {
        if (head->val < 10 && head->val > 0)
        {
            return temp1;
        }
        else
        {
            if (head->next == NULL)
            {
                head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                head->next->next = NULL;
                head->next->val = 0;
            }
            //head->val = 0;
            dirr = (head->val) / 10;
            head->val = (head->val) % 10;

            head->next->val += dirr;
            dirr = 0;
            if (head->next->val < 10)
            {
                return temp1;
            }
            else
            {
                head = head->next;
            }
        }
    }
}
// @lc code=end
