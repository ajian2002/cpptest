#include <stdio.h>
#include <string.h>
// #include "sinlinklist1.h"
#include "sinlinklist1.h"
#include "../leecode/2.两数相加.c"
int main()
{
    struct ListNode *head = creaklink(1, 9);
    head = pushlink(head, 9);
    head = pushlink(head, 9);
    head = pushlink(head, 9);
    head = pushlink(head, 9);
    struct ListNode *head2 = creaklink(1, 9);
    head2 = pushlink(head2, 9);
    head2 = pushlink(head2, 9);
    //输入
    seelink(head);
    seelink(head2);
    struct ListNode *head3 = addTwoNumbers(head, head2);
    seelink(head3);
    dellink(head3);
    //dellink(head);
    //dellink(head2);
}