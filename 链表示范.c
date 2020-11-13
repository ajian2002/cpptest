#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// 创建列表
int initList(struct Node **linkList);
// 头插法
int headInsert(struct Node *linkList);
// 尾插法
int tailInsert(struct Node *linkList);
// 获取结点
int getNode(struct Node *linkList, int index, struct Node **node);
// 获取结点数据
int getData(struct Node *linkList, int index, int *data);
// 设置结点数据
int setData(struct Node *linkList, int index, int data);
// 插入结点
int insert(struct Node *linkList, int index);
// 删除结点
int removeNode(struct Node *linkList, int index);
// 获取数组长度
int getLength(struct Node *linkList);
// 查找数据
int find(struct Node *linkList, int data);
// 整表创建
int createList(int nums[], int size, struct Node **linkList);
// 整表删除
void removeList(struct Node **linkList);
// 链表逆置
void reverse(struct Node *linkList);

int main()
{
    struct Node *linkList;
    printf("initList:%d", initList(&linkList));
    struct Node *node;
    printf("length:%d\n", getLength(linkList));
    printf("tailInsert:%d\n", tailInsert(linkList));
    printf("length:%d\n", getLength(linkList));
    printf("headInsert:%d\n", headInsert(linkList));
    printf("length:%d\n", getLength(linkList));
    printf("getNode:%d\n", getNode(linkList, 0, &node));
    node->data = 10;
    int *p = (int *)malloc(sizeof(int));
    printf("getData:%d\n", getData(linkList, 0, p));
    printf("data:%d\n", *p);
    printf("setData:%d\n", setData(linkList, 1, 5));
    getData(linkList, 1, p);
    printf("data:%d\n", *p);
    printf("insert:%d\n", insert(linkList, 1));
    printf("length:%d\n", getLength(linkList));
    printf("removeNode:%d\n", removeNode(linkList, 1));
    printf("removeNode:%d\n", removeNode(linkList, 0));
    printf("length:%d\n", getLength(linkList));
    printf("find:%d\n", find(linkList, 5));
    removeList(&linkList);
    printf("removeList:%p\n", linkList);
    int nums[5] = {1, 3, 5, 7, 9};
    printf("createList:%d\n", createList(nums, 5, &linkList));
    reverse(linkList);
    printf("reverse:\n");
    printf("%d\n", linkList->next->next->next->data);
    printf("length:%d\n", getLength(linkList));
    removeList(&linkList);
    printf("removeList:%p\n", linkList);

    return 0;
}

// 如果初始化成功则返回0，否则返回1
int initList(struct Node **linkList)
{
    // 为头结点分配空间
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    // 悲观地假设一个错误
    int result = 1;

    if (head)
    {
        *linkList = head;
        head->next = NULL;
        result = 0;
    }

    return result;
}

// 如果分配内存失败则返回1，否则返回0
int headInsert(struct Node *linkList)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    if (node)
    {
        node->next = linkList->next;
        linkList->next = node;

        return 0;
    }

    return 1;
}

// 如果分配内存失败则返回1，否则返回0
int tailInsert(struct Node *linkList)
{
    struct Node *current = linkList;

    while (current->next)
    {
        current = current->next;
    }

    current->next = (struct Node *)malloc(sizeof(struct Node));

    if (current->next)
    {
        current = current->next;
        current->next = NULL;

        return 0;
    }

    return 1;
}

// 如果链表索引越界则返回1，否则返回0
int getNode(struct Node *linkList, int index, struct Node **node)
{
    struct Node *current = linkList;
    int i = -1;

    while (i < index)
    {
        if (!current->next)
        {
            *node = NULL;

            return 1;
        }
        current = current->next;
        i++;
    }

    *node = current;

    return 0;
}

// 如果链表索引越界则返回1，否则返回0
int getData(struct Node *linkList, int index, int *data)
{
    struct Node *node;
    int result = getNode(linkList, index, &node);

    if (!result)
    {
        *data = node->data;
    }

    return result;
}

// 如果链表索引越界则返回1，否则返回0
int setData(struct Node *linkList, int index, int data)
{
    struct Node *node;
    int result = getNode(linkList, index, &node);

    if (!result)
    {
        node->data = data;
    }

    return result;
}

// 如果索引越界返回1，内存分配失败返回2，否则返回0
int insert(struct Node *linkList, int index)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *preNode;
    int result;

    if (!node)
    {
        result = 2;
    }
    else
    {
        result = getNode(linkList, index - 1, &preNode);

        if (!result)
        {
            node->next = preNode->next;
            preNode->next = node;
        }
    }

    return result;
}

// 如果链表索引越界则返回1，否则返回0
int removeNode(struct Node *linkList, int index)
{
    struct Node *preNode;
    struct Node *node;
    int result = getNode(linkList, index - 1, &preNode);

    if (!result)
    {
        node = preNode->next;

        if (!node)
        {
            result = 1;
        }
        else
        {
            preNode->next = node->next;
            free(node);
        }
    }

    return result;
}

int getLength(struct Node *linkList)
{
    struct Node *current = linkList;
    int index = -1;

    while (current->next)
    {
        current = current->next;
        index++;
    }

    return index + 1;
}

// 如果未找到数据，则返回-1
int find(struct Node *linkList, int data)
{
    struct Node *current = linkList;
    int index = -1;

    while (current->next)
    {
        current = current->next;
        index++;

        if (current->data == data)
        {
            return index;
        }
    }

    return -1;
}

// 如果创建成功则返回0，否则返回1
int createList(int nums[], int size, struct Node **linkList)
{

    int result;
    int i;
    struct Node *head;
    struct Node *current;

    result = initList(&head);
    current = head;

    if (!result)
    {
        for (i = 0; i < size; i++)
        {
            current->next = (struct Node *)malloc(sizeof(struct Node));

            if (!current->next)
            {
                result = 1;
                break;
            }

            current = current->next;
            current->next = NULL;
            current->data = nums[i];
        }

        *linkList = head;
    }

    return result;
}

void removeList(struct Node **linkList)
{
    struct Node *node = *linkList;

    while (*linkList)
    {
        *linkList = node->next;
        free(node);
        node = *linkList;
    }

    return;
}

void reverse(struct Node *linkList)
{
    struct Node *initialNode;
    struct Node *node;

    // 判断是否是空表
    if (linkList->next)
    {
        initialNode = linkList->next;

        while (initialNode->next)
        {
            node = initialNode->next;
            initialNode->next = node->next;
            node->next = linkList->next;
            linkList->next = node;
        }
    }

    return;
}
