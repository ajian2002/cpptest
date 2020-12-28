#include <stdio.h>
#include <string.h>
// #include "sinlinklist1.h"
#include "sinlinklist1.h"
#include "../leecode/203.移除链表元素.c"
int main()
{
  struct ListNode *head = creaklink(1, 1);
  head = pushlink(head, 2);
  head = pushlink(head, 1);

  //输入
  seelink(head);
  struct ListNode *head3 = removeElements(head, 2);
  seelink(head3);
  dellink(head);

  //dellink(head);
  //dellink(head2);
}