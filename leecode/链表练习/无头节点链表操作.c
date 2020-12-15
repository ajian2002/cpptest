//无头节点单链表的创建，末尾插入，末尾删除，删除第k节点
//带头节点的单链表如上操作
//递归和非递归反转单链表
//获取长度为k单链表的中点（向下取整）的指针
#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int data;
    struct link *next;
} linklist;

void pop(linklist *link);                //尾删
void *push(linklist *link, int data);    //尾插
void *godata(linklist *link, int where); //获取指定节点（无头）
//获取指定节点(有头)  godata(link->next,where)
void deldata(linklist *link, int where); //删除指定节点(无头)
//删除指定节点(有头)  deldata(link->next,where)
void *creaklink(void);        //创建链表
void seelink(linklist *link); //查看链表
//查看有头链表   seelink(head->next);
void del(linklist *link);      //整表删
void reverse1(linklist *link); //递归逆置
void reverse2(linklist *link); //非递归逆置
int main()
{
    printf("无头单链表的创建，末尾插入，末尾删除，删除第3节点\n");
    linklist *frist = NULL;

    frist = push(frist, 1);
    seelink(frist);
    push(frist, 2);
    seelink(frist);
    push(frist, 3);
    seelink(frist);
    push(frist, 4);
    seelink(frist);
    deldata(frist, 3);
    seelink(frist);
    pop(frist);
    seelink(frist);
    reverse1(frist);
    seelink(frist);
    reverse2(frist);
    seelink(frist);
    del(frist);
    printf("无头单链表的创建，末尾插入，末尾删除，删除第3节点\n");
    linklist *head = creaklink();
    push(head, 1);
    seelink(head->next);
    push(head, 2);
    seelink(head->next);
    push(head, 3);
    seelink(head->next);
    push(head, 4);
    seelink(head->next);
    deldata(head->next, 3);
    seelink(head->next);
    pop(head);
    seelink(head->next);
    reverse1(head);
    seelink(head);
    reverse2(head);
    seelink(head);
    del(head);
}

void *creaklink(void) //无头
{
    linklist *frist = (linklist *)malloc(sizeof(linklist));
    if (frist == NULL)
    {
        printf("creat failed");
        exit(0);
    }
    frist->next = NULL;
    return frist;
}

void pop(linklist *link)
{
    linklist *temp = link;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
void *push(linklist *link, int data)
{
    linklist *temp = (linklist *)malloc(sizeof(linklist));
    if (link == NULL)
    {
        link = temp;
        link->data = data;
        link->next = NULL;
        return link;
    }
    else
    {

        if (!temp)
            exit(1);
        temp->next = NULL;
        temp->data = data;
        //找到最后一项
        linklist *find = link;
        while (find->next != NULL)
        {
            find = find->next;
        }

        find->next = temp;
        return link;
    }
}

void seelink(linklist *link) //无头
{
    linklist *temp = link;
    if (link == NULL)
        return;

    //linklist *temp = link;//有头
    do
    {
        printf("%d ", temp->data);
        if (temp->next)
            temp = temp->next;
        else
            break;
    } while (temp);

    printf("\n");
}
void del(linklist *link)
{
    while (link)
    {
        linklist *temp = link;
        if (link->next)
            link = link->next;
        else
        {
            free(link);
            return;
        }
        free(temp);
    }
    free(link);
}
void *golink(linklist *link, int where)
{
    linklist *temp = link;
    for (int i = 1; i < where; i++)
    {
        if (temp)
        {
            temp = temp->next;
        }
        else
        {
            printf("find error");
            return NULL;
        }
    }
    return temp;
}
void deldata(linklist *link, int where)
{
    linklist *temp = link;
    for (int i = 2; i < where; i++)
    {
        if (temp)
        {
            temp = temp->next;
        }
        else
        {
            printf("del error");
            return;
        }
    }
    linklist *tt;
    if (where == 1)
    {
        free(link);
    }
    else
    {
        tt = temp->next;
        temp->next = temp->next->next;
        free(tt);
    }
}
void reverse1(linklist *link) //递归逆置
{
}
void reverse2(linklist *link) //非递归逆置
{
}