#include "Double-circular-list.h"

//typedef TYPE int;
typedef struct node
{
    void *data;
    //int data;
    struct node *prev;
    struct node *next;
} Node;

struct list
{
    struct node *head;
    int datasize;
    int length;
};

/*
typedef struct node* Iterator;
typedef struct list* List;
*/

//创建
struct list *initList(struct list **list, struct node *node)
{
    struct list *temp = (struct list *)malloc(sizeof(struct list));
    if (temp == NULL)
        exit(1);
    temp->datasize = sizeof(struct node);
    temp->length = 1;
    temp->head = node;

    if (temp->head != NULL)
    {
        *list = temp;
    }
    else
    {
        *list = NULL;
    }
    return *list;
}

//删除链表
struct list *removeList(struct list **list)
{
    if (*list == NULL || list == NULL)
        exit(-1);

    struct node *current;
    current = (*list)->head;
    if (current == NULL)
    {
        free(*list);
        *list = NULL;
    }
    else
    {
        while (current != NULL)
        {
            struct node *pordata;
            pordata = current;
            if ((*list)->length == 1)
            {
                current = NULL;
            }
            else if ((*list)->length == 2)
            {
                pordata->prev->next = pordata->prev;
                pordata->next->prev = pordata->next;
                current = pordata->next;
            }
            else
            {
                pordata->prev->next = pordata->next;
                pordata->next->prev = pordata->prev;
                current = pordata->next;
            }
            if (pordata->data)
            {
                free(pordata->data);
                pordata->data = NULL;
            }
            free(pordata);
            (*list)->length--;
            (*list)->datasize -= sizeof(struct node);
        }
        free(*list);
        *list = NULL;
    }
    return *list;
}

// 创建节点
struct node *initNode(void *data, int count)
{
    struct node *s = (struct node *)malloc(sizeof(struct node));
    if (s == NULL)
        exit(-1);
    s->data = malloc(1 + count);
    memset(s->data, 'a', count + 1);
    memcpy(s->data, data, count);
    s->next = s->prev = s;
    return s;
}

//头插法
struct list *headInsertNode(struct list *list, struct node *node)
{

    if (!(node && list))
        exit(1);

    if (list->head->data == NULL)
    {
        node->next = node;
        node->prev = node;
        free(list->head);
        list->head = node;
    }
    else
    {
        node->next = list->head;
        node->prev = list->head->prev;

        list->head->prev->next = node;
        list->head->prev = node;
        list->head = node;
    }
    list->length++;
    list->datasize += sizeof(struct node);
    return list;
}

// 尾插法
struct list *tailInsertNode(struct list *list, struct node *node)
{
    if (!(node && list))
        exit(1);
    if (list->head->data == NULL)
    {
        node->next = node;
        node->prev = node;
        free(list->head);
        list->head = node;
    }
    else
    {
        node->next = list->head;
        node->prev = list->head->prev;

        list->head->prev->next = node;
        list->head->prev = node;
    }
    list->length++;
    list->datasize += sizeof(struct node);
    return list;
}

// 删除第index个节点
struct list *removeindexNode(struct list *list, int index)
{
    if (index > list->length)
        exit(-1);
    struct node *temp = list->head;
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;

    if (list->length > 1) //大于1
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (list->head == temp)
            list->head = temp->next;
    }
    if (temp->data)
    {
        free(temp->data);
        temp->data = NULL;
    }
    free(temp);
    list->length--;
    list->datasize -= sizeof(struct node);
    if (list->length == 0)
        list->head = NULL;
    return list;
}

// 删除值为key节点
struct list *removekeyNode(struct list *list, void *key, int count)
{
    struct node *temp = list->head;
    char *p = (char *)(temp->data);
    int j = list->length;
    for (int i = 0; i < j; i++)
    {
        if (temp == NULL || p == NULL)
            exit(-1);
        if (strncmp(p, (char *)key, count) == 0)
        {

            struct node *tt = temp;
            if (temp->prev != temp->next)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            else
            {
                temp->prev->next = temp->prev;
                temp->next->prev = temp->next;
            }
            temp = tt->next;
            p = temp->data;
            if (list->head == tt)
                if (list->length > 1)
                {
                    list->head = tt->next;
                }
            if (tt->data)
            {
                free(tt->data);
                tt->data = NULL;
            }
            free(tt);
            list->length--;
            list->datasize -= sizeof(struct node);
        }
        else
        {
            temp = temp->next;
            if (temp && temp->data)
                p = (char *)temp->data;
        }
    }
    if (list->length == 0)
        list->head = NULL;
    return list;
}

// 修改第index个节点
void *modifyNode(struct list *list, int index)
{
    if (index > list->length)
        exit(-1);
    struct node *temp = list->head;
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;
    return (temp->data);
}

//查找第index个节点
struct node *findindexNode(struct list *list, int index)
{
    if (index > list->length)
        return NULL;
    struct node *temp = list->head;
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;
    return temp;
}

//查找值为key的节点
struct node *findkeyNode(struct list *list, void *key, int count, int begin)
{
    struct node *re = NULL;
    if (begin > list->length)
        exit(-1);
    struct node *temp = list->head;
    for (int i = 0; i < begin - 1; i++)
        temp = temp->next;
    char *p = (char *)(temp->data);
    int j = list->length;
    for (int i = 0; i < j; i++)
    {
        if (strncmp(p, (char *)key, count) == 0)
        {
            re = temp;
            break;
        }
        else
        {
            temp = temp->next;
            p = (char *)(temp->data);
        }
    }
    return re;
}

//查看void*  int
void seeintdata(struct list *list)
{
    int len = list->length;
    struct node *temp = list->head;
    for (int i = 0; i < len; i++)
    {
        printf("%d :%d\n", i, *(int *)(temp->data));
        temp = temp->next;
    }
}
//查看void*  字符串
void seestrdata(struct list *list)
{
    int len = list->length;
    struct node *temp = list->head;
    for (int i = 0; i < len; i++)
    {
        printf("%d :%d\n", i, *(int *)(temp->data));
        temp = temp->next;
    }
}