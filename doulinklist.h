#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} linklist;
//尾删
void *poplink(linklist *link)
{
    linklist *temp = link;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return link;
}

//尾插
void *pushlink(linklist *link, int data)
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

//获取指定节点（无头）
//获取指定节点(有头)  godata(link->next,where)
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

//删除指定节点(无头)
//删除指定节点(有头)  deldata(link->next,where)
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

//创建链表
//if 0 1判断有无头节点数据
void *creaklink(int IF, int data)
{
    struct node *frist = (struct node *)malloc(sizeof(struct node));
    if (frist == NULL)
    {
        printf("creat failed");
        exit(0);
    }
    if (IF)
        frist->data = data;
    frist->next = NULL;
    return frist;
}

//查看链表
//查看有头链表   seelink(head->next);
void seelink(linklist *link)
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

//整表删
void dellink(linklist *link)
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

//非递归逆置
void *reslink(linklist *link);