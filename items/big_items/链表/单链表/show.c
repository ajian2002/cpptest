//无头节点单链表的创建，末尾插入，末尾删除，删除第k节点 yes
//带头节点的单链表如上操作                         yes
//递归和非递归反转单链表
//获取长度为k单链表的中点（向下取整）的指针

#include <my/sinlinklist.h>
struct Date
{
    int intdata;
    void *voiddata;
};
#include <stdio.h>
#include <string.h>
//查看链表
void seelink(listnode *link)
{
    listnode *temp = link;
    if (link == NULL)
        return;

    //listnode *temp = link;//有头
    do
    {
        printf("%d ", temp->item->intdata);
        if (temp->next)
            temp = temp->next;
        else
            break;
    } while (temp);

    printf("\n");
}

/*用户
1.定义 struct Date结构体内容
2.(可选)编写查看函数(接受listnode*,打印item项中的各种数据)
3.明确删除时使用delonlylink函数还是delalllink函数
4.(可选)对链表中item的操作都需要自行构造一个item替换(不建议直接访问)
*/

int main()
{
    Item data[10];
    for (int i = 0; i < 10; i++)
    {
        data[i].intdata = i;
    }
    listnode *head = sinlinklist_creatlink(&data[0]);
    seelink(head);
    //head = sinlinklist_pushlink(head, &data[1]);
    //head = sinlinklist_pushlink(head, &data[2]);
    head = sinlinklist_pushlink(head, &data[3]);
    //seelink(head);
    //head = sinlinklist_poplink(head);
    seelink(head);
    Item *s = sinlinklist_getnitem(head, 1);
    printf("%d\n", s->intdata);
    printf("%d\n", sinlinklist_getlenlink(head));
    head = sinlinklist_reslink(head);
    seelink(head);
    head = sinlinnklist_headinsert(head, &data[6]);
    seelink(head);
    sinlinklist_delonlylink(head);
}
