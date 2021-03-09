#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    //  struct node *prev;
} linklist;

//尾删
void *poplink(linklist *link);

//尾插
void *pushlink(linklist *link, int data);
//获取k点
void *golink(linklist *link, int where);
//删除k点
//  head = deldata(head, 1);
void *deldata(linklist *link, int where);
//创建链表
//if 1 0判断有无头节点数据
//无头不存数据 main另存第一项，
//有头直接存
void *creaklink(int IF, int data);

//查看链表
void seelink(linklist *link);
//整表删
void dellink(linklist *link);
//递归逆置
void *reslink8(linklist *link);
//非递归逆置（原地逆置）
void *reslink(linklist *link);
//获取链表长度
int getlenlink(linklist *link);
