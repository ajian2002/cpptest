#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
    //  struct node *prev;
};
//尾删
void *poplink(struct ListNode *link)
{
    struct ListNode *temp = link;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return link;
}

//尾插
void *pushlink(struct ListNode *link, int val)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (link == NULL)
    {
        link = temp;
        link->val = val;
        link->next = NULL;
        return link;
    }
    else
    {

        if (!temp)
            exit(1);
        temp->next = NULL;
        temp->val = val;
        //找到最后一项
        struct ListNode *find = link;
        while (find->next != NULL)
        {
            find = find->next;
        }

        find->next = temp;
        return link;
    }
}

//获取k点
void *golink(struct ListNode *link, int where)
{
    struct ListNode *temp = link;
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
//  head = delval(head, 1);
void *delval(struct ListNode *link, int where)
{
    struct ListNode *temp = link;
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

        struct ListNode *tt;
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
void *creaklink(int IF, int val)
{
    struct ListNode *frist = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (frist == NULL)
    {
        printf("creat failed");
        exit(0);
    }
    if (IF)
        frist->val = val;
    frist->next = NULL;
    return frist;
}

//查看链表
void seelink(struct ListNode *link)
{
    struct ListNode *temp = link;
    if (link == NULL)
        return;

    //ListNode *temp = link;//有头
    do
    {
        printf("%d ", temp->val);
        if (temp->next)
            temp = temp->next;
        else
            break;
    } while (temp);

    printf("\n");
}

//整表删
void dellink(struct ListNode *link)
{
    while (link)
    {
        struct ListNode *temp = link;
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
void *reslink8(struct ListNode *link)
{
    if (!link || !link->next)
    {
        return link;
    }
    struct ListNode *temp = reslink8(link->next); //temp是最后一项的指针
    link->next->next = link;
    link->next = NULL;
    return temp;
}
//非递归逆置（原地逆置）
void *reslink(struct ListNode *link)
{
    if (!link || !link->next)
        return link;
    else
    {
        struct ListNode *prev = NULL;
        struct ListNode *xia = link->next;
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
int getlenlink(struct ListNode *link)
{
    int count = 0;
    while (link)
    {
        count++;
        link = link->next;
    }
    return count;
}

//逆序函数进阶
//特殊函数 得定义在函数内
/* 
//printf("\n前n个节点逆序\n");

    //必须函数内定义
    ListNode *xia = NULL;
    void *renserve(ListNode * link, int n)
    {

        if (n == 1)
        {
            xia = link->next; //存下一个节点的位置
            return link;
        }
        ListNode *temp = renserve(link->next, n - 1);
        //返回排序好的队列队首
        //link （temp）（xia 剩余）
        link->next->next = link;
        link->next = xia;
        return temp;
    }
    /*
    head = renserve(head, 3);
    seelink(head);
    printf("\n");
    
printf("\n指定区间逆序\n");
//函数内定义
void *rennserve(ListNode *link, int b, int e)
{

    if (b == 1) //开始逆序
    {
        return renserve(link, e);
    }
    ListNode *temp = rennserve(link->next, b - 1, e - 1);
    //返回了反转后的部分队列的队首，link是开始反转的前一个位置
    //反转后的后半部分队列简化为（temp）
    //head  node node （link） （temp）剩余
    link->next = temp;
    return link;
}
head = rennserve(head, 2, 4);
seelink(head);
printf("\n");


*/
