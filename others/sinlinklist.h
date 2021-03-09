#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    //  struct node *prev;
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

//获取k点
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

//删除k点
//  head = deldata(head, 1);
void *deldata(linklist *link, int where)
{
    linklist *temp = link;
    if (where == 1) //有头
    {
        temp = link->next;

        //link = &temp;
        free(link);
        return temp;
    }
    else
    {
        for (int i = 2; i < where; i++)
        {
            if (temp)
            {
                temp = temp->next;
            }
            else
            {
                printf("del error");
                exit(-1);
            }
        }

        linklist *tt;
        tt = temp->next;
        temp->next = temp->next->next;
        free(tt);
    }
    return link;
}

//创建链表
//if 1 0判断有无头节点数据
//无头不存数据 main另存第一项，
//有头直接存
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

//递归逆置
void *reslink8(linklist *link)
{
    if (!link || !link->next)
    {
        return link;
    }
    linklist *temp = reslink8(link->next); //temp是最后一项的指针
    link->next->next = link;
    link->next = NULL;
    return temp;
}
//非递归逆置（原地逆置）
void *reslink(linklist *link)
{
    if (!link || !link->next)
        return link;
    else
    {
        linklist *prev = NULL;
        linklist *now = link;
        linklist *xia = link->next;
        while (xia)
        {
            link->next = prev;
            prev = link;
            link = xia;
            xia = xia->next;
        }
        link->next = prev;
        return link;
    }
}

//获取链表长度
int getlenlink(linklist *link)
{
    int count = 0;
    while (link)
    {
        count++;
        link = link->next;
    }
    return count;
}
