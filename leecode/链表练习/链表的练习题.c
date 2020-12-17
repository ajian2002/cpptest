//无头节点单链表的创建，末尾插入，末尾删除，删除第k节点 yes
//带头节点的单链表如上操作                         yes
//递归和非递归反转单链表
//获取长度为k单链表的中点（向下取整）的指针

#include "sinlinklist.h"

void *getmidlink(linklist *link, int k); // 获取长度为k单链表的中点（向下取整）的指针
int main()
{
    linklist *temp;
    printf("无头单链表:\n");
    linklist *frist = NULL;

    //frist = pushlink(frist, 1);
    frist = creaklink(0, 66); //无头不存数据
    frist->data = 1;
    seelink(frist);
    printf("尾插开始\n");
    pushlink(frist, 2);
    seelink(frist);
    pushlink(frist, 3);
    seelink(frist);
    pushlink(frist, 4);
    seelink(frist);
    printf("递归逆置\n");
    frist = reslink8(frist);
    seelink(frist);
    printf("原地逆置\n");
    frist = reslink(frist);
    seelink(frist);

    printf("定点删除第1节点\n");
    frist = deldata(frist, 1);
    seelink(frist);
    printf("尾删\n");
    poplink(frist);
    seelink(frist);

    temp = frist;
    printf("打印链表中点之后的数据\n");
    temp = getmidlink(frist, getlenlink(frist));
    seelink(temp);
    dellink(frist);

    //2
    printf("\n有头单链表:\n");
    linklist *head = creaklink(1, 1); //有头存数据

    printf("尾插开始\n");
    pushlink(head, 1);
    //长度自增
    head->data += 1;
    seelink(head);
    pushlink(head, 2);
    head->data += 1;
    seelink(head);
    pushlink(head, 3);
    head->data += 1;
    seelink(head);
    pushlink(head, 4);
    head->data += 1;
    seelink(head);
    printf("递归逆置\n");
    head = reslink8(head);
    seelink(head);
    printf("原地逆置\n");
    head = reslink(head);
    seelink(head);

    //printf("%d\n", head->data);
    //printf("%d\n", getlenlink(head));

    printf("定点删除第3节点\n");
    head = deldata(head, 3);
    head->data -= 1;
    seelink(head);
    printf("尾删\n");
    poplink(head);
    head->data -= 1;
    seelink(head);
    temp = head;
    printf("打印链表中点之后的数据\n");
    temp = getmidlink(head, getlenlink(head));
    seelink(temp);

    dellink(head);
}

void *getmidlink(linklist *link, int k) // 获取长度为k单链表的中点（向下取整）的指针
{
    k = k / 2;

    for (int i = 0; i < k; i++)
    {
        link = link->next;
    }

    return link;
}