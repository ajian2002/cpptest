#include <stdio.h>
#include <stdlib.h>
int NUMBER = 2;
//声明直接搬运,各函数自己实现
struct Node
{
    int data;
    struct Node *next;
};

// 创建列表
int initList(struct Node **linkList);
// 头插法
int headInsert(struct Node **linkList);
// 尾插法
int tailInsert(struct Node **linkList);
// 获取结点
void getNode(struct Node **linkList, int NUMBER);
// 获取结点数据
int getData(struct Node **linkList, int NUMBER);
// 设置结点数据
int setData(struct Node **linkList, int index, int data);
// 插入结点
int insert(struct Node **linkList, int index, int data);
// 删除结点
void removeNode(struct Node **linkList, int index);
// 获取链表长度
int getLength(struct Node **linkList);
// 查找数据
int find(struct Node **linkList, int data);
// 整表创建
void createList(int nums[], int size, struct Node **newlinkList);
// 整表删除
int removeList(struct Node **newlinkList);
// 链表逆置
void reverse(struct Node **linkList);
//查看链表数据
void seelink(struct Node *link);

int main()
{
    struct Node **linkList;
    int error = 0;
    // int size = 10;
    // int nums[size] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    printf("创建返回%d\n", error = initList(linkList));
    seelink(*linkList);
    printf("头插返回%d\n", error = headInsert(linkList));
    seelink(*linkList);
    printf("尾插返回%d\n", error = tailInsert(linkList));
    seelink(*linkList);
    //获取节点
    getNode(linkList, NUMBER);
    seelink(*linkList);
    //获取节点数据
    printf("%d\n", error = getData(linkList, NUMBER + 1));
    seelink(*linkList);
    //设置节点数据
    printf("设置节点%d数据为%d  ", NUMBER + 1, error = setData(linkList, 3, 4));
    printf("设置节点%d数据为%d  ", NUMBER - 1, error = setData(linkList, 1, 1));
    printf("设置节点%d数据为%d\n", NUMBER, error = setData(linkList, 2, 2));
    seelink(*linkList);
    //插入节点
    printf("插入节点%d为%d\n", 3, error = insert(linkList, 3, 3));
    seelink(*linkList);
    //删除节点
    printf("删除节点%d\n", 2);
    removeNode(linkList, 2);
    seelink(*linkList);
    printf("获取链表长度为%d\n", error = getLength(linkList));
    printf("查找数据%d位置为%d\n", 4, error = find(linkList, 4));

    printf("设置节点%d数据为%d  ", 2, error = setData(linkList, 2, 2));
    printf("设置节点%d数据为%d\n", 3, error = setData(linkList, 3, 3));
    seelink(*linkList);
    //整表创建
    //printf("1");
    struct Node A;
    struct Node *nesw = &A;
    struct Node **newlinkList = &nesw;

    // initList(newlinkList); printf("1");

    int nums[6] = {11, 12, 13, 14, 15};
    //printf("1");
    createList(nums, 5, newlinkList);
    printf("新");
    seelink(*newlinkList);

    printf("删除表%d\n", error = removeList(newlinkList));
    printf("新");
    seelink(*newlinkList);
    printf("  原");
    seelink(*linkList);
    //printf(" ");
    reverse(linkList);

    printf("逆置");
    seelink(*linkList);
}

// 创建列表
int initList(struct Node **linkList)
{
    struct Node *current;
    if ((current = (struct Node *)malloc(sizeof(struct Node))) == NULL)
        return 0;
    else
    {

        current->data = 1;
        current->next = NULL;
        *linkList = current;
        return 1;
    }
}
// 头插法
int headInsert(struct Node **linkList)
{
    struct Node *current;
    current = (struct Node *)malloc(sizeof(struct Node));
    if (current == NULL)
        return 0;
    else
    {

        current->next = *linkList;
        current->data = -1;
        *linkList = current;
        return 1;
        //struct Node ;
    }
}

// 尾插法
int tailInsert(struct Node **linkList)
{
    struct Node *current, *tailInsert;
    tailInsert = (struct Node *)malloc(sizeof(struct Node));
    current = *linkList;
    if (current->next == NULL || tailInsert == NULL)
        return 0;
    else
    { //current->next = *linkList;
        while (current->next != NULL)
            current = current->next;

        current->next = tailInsert;
        tailInsert->data = 999;
        tailInsert->next = NULL;
    }
    return 1;
}
// 获取结点
void getNode(struct Node **linkList, int NUMBER)
{
    struct Node *current; //, *tailInsert;
                          //  tailInsert = (struct Node *)malloc(sizeof(struct Node));
    current = *linkList;
    if (current->next != NULL)
        for (int i = 0; i < NUMBER - 1; i++)
            current = current->next;
    if (current->data)
    {
        printf("已确认节点%d存在,为%d\n", NUMBER, current->data);
        //  return 1;
    }
    else
    {
        printf("节点%d不存在\n", NUMBER);
        //return 0;
    }
}
// 获取结点数据
int getData(struct Node **linkList, int number)
{
    struct Node *current;
    current = *linkList;
    if (current->next != NULL)
        for (int i = 0; i < number - 1; i++)
            current = current->next;
    if (current->data)
    {
        printf("获取节点%d数据为", number);

        return current->data;
    }
    else
    {
        printf("不存在返回");
        return 0;
    }
}
//设置结点
int setData(struct Node **linkList, int index, int data)
{
    struct Node *current;
    current = *linkList;
    if (current->next != NULL)
        for (int i = 0; i < index - 1; i++)
            current = current->next;
    current->data = data;
    current = *linkList;
    *linkList = current;
    return data;
}
// 插入结点
int insert(struct Node **linkList, int index, int data)
{
    struct Node *current, *tailInsert;
    tailInsert = (struct Node *)malloc(sizeof(struct Node));
    current = *linkList;
    if (current == NULL || tailInsert == NULL)
        return 0;
    else
    {
        for (int i = 1; i < index - 1; i++)
            current = current->next;
        tailInsert->next = current->next->next;
        tailInsert->data = current->next->data;
        current = current->next;
        current->data = data;
        current->next = tailInsert;
    }
    return current->data;
}
// 删除结点
void removeNode(struct Node **linkList, int index)
{
    struct Node *current, *tailInsert;
    current = *linkList;
    if (current != NULL)
    { //current->next = *linkList;
        for (int i = 0; i < index - 2; i++)
            current = current->next;

        if (current->next->next == NULL)
            current->next = NULL;
        else
        {
            tailInsert = current->next;
            current->next = current->next->next;
            free(tailInsert);
        }
    }
}
// 获取链表长度
int getLength(struct Node **linkList)
{
    int length = 0;
    struct Node *current = *linkList;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}
// 查找数据
int find(struct Node **linkList, int data)
{
    int sum = 1;
    struct Node *current = *linkList;
    if (current == NULL)
        return -1;
    else
    {
        while (current != NULL && current->data != data)
        {
            current = current->next;
            sum++;
        }
        if (current->data == data)
            return sum;
    }
    return -1;
}
// 整表创建
void createList(int nums[], int size, struct Node **newlinkList)
{
    struct Node *current = (struct Node *)malloc(sizeof(struct Node));
    *newlinkList = current;
    for (int i = 0; i < size; i++)
    {
        current->data = nums[i];
        if (i != size - 1)
        {
            struct Node *pordata = (struct Node *)malloc(sizeof(struct Node));
            current->next = pordata;
            current = current->next;
        }
        else
        {
            current->next = NULL;
        }
        // current = NULL;
    }
}
// 整表删除
int removeList(struct Node **newlinkList)
{
    struct Node *current, *pordata;
    current = *newlinkList;
    while (current->next != NULL)
    {
        struct Node *pordata;
        pordata = current;
        current = current->next;
        free(pordata);
    }
    //printf("1");
    free(pordata);
    *newlinkList = NULL;
    return 1;
}
// 链表逆置
void reverse(struct Node **linkList)
{
    struct Node *cur = *linkList;
    int i = 1;
    struct Node *pro;
    struct Node *xx;

    xx = cur->next;
    cur->next = NULL;
    pro = cur;
    //  printf("%d", (*cur).data); //1
    cur = xx;
    //  xx = cur->next;
    while (cur->next != NULL)
    {

        i++;
        // printf("%d ", i);

        xx = cur->next;
        cur->next = pro;

        pro = cur;
        // printf("%d", (*cur).data);
        cur = xx;
    }

    cur->next = pro;
    *linkList = cur;
    //printf("%d %d %d", (*cur).data, (*(cur->next)).data, (*((cur->next)->next)).data); //1
}
//查看链表数据
void seelink(struct Node *linkList)
{
    struct Node *prev = linkList;
    if (prev != NULL)

    {
        printf("链表:%d ", prev->data);
        while (prev->next != NULL)
        {
            prev = prev->next;
            printf("%d ", prev->data);

            //  printf("1 ");
        }
    }
    else
        printf("表空");
    printf("\n");
}

{
    
}