/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (40.65%)
 * Likes:    1156
 * Dislikes: 0
 * Total Accepted:    299.8K
 * Total Submissions: 737.6K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
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

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *temp = head;
    struct ListNode *left, *right;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            left = temp;
        if (i == n - 1)
            right = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return left->next;

    while (temp->next != NULL)
    {
        left = left->next;
        right = right->next;
        temp = temp->next;
    }
    left->next = left->next->next;
    return head;
}
// @lc code=end
