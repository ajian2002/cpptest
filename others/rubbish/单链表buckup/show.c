//无头节点单链表的创建，末尾插入，末尾删除，删除第k节点 yes
//带头节点的单链表如上操作                         yes
//递归和非递归反转单链表
//获取长度为k单链表的中点（向下取整）的指针
struct Date
{
    int data;
};
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
    printf("\n有头单链表:头结点存链表长度\n");
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
    /*
    //逆序函数进阶
    //printf("\n前n个节点逆序\n");

    //必须函数内定义
    linklist *xia = NULL; 
    void *renserve(linklist * link, int n)
    {

        if (n == 1)
        {
            xia = link->next; //存下一个节点的位置
            return link;
        }
        linklist *temp = renserve(link->next, n - 1);
        //返回排序好的队列队首
        //link （temp）（xia 剩余）
        link->next->next = link;
        link->next = xia;
        return temp;
    }
    

    printf("\n");
    
    printf("\n指定区间逆序\n");
    //函数内定义
    void *rennserve(linklist * link, int b, int e)
    {

        if (b == 1) //开始逆序
        {
            return renserve(link, e);
        }
        linklist *temp = rennserve(link->next, b - 1, e - 1);
        //返回了反转后的部分队列的队首，link是开始反转的前一个位置
        //反转后的后半部分队列简化为（temp）
        //head  node node （link） （temp）剩余
        link->next = temp;
        return link;
    }
    head=rennserve(head, 3, 4);
    seelink(head);
    printf("\n");
    */

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