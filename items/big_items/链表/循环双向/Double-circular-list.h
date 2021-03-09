#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _DOUBLE_CIRCULAR_LINKLIST_
#define _DOUBLE_CIRCULAR_LINKLIST_

//循环双链表
typedef struct node *Iterator;
typedef struct list *List;

/*
typedef struct node
{
    void *data;
    struct node *prev;
    struct node *next;
} Node;

struct list
{
    struct node *head;
    int datasize;
    int length;
};*/

//对外接口

// 创建列表
List initList(List *list, Iterator node);

//删除链表
List removeList(List *list);

//创建节点
Iterator initNode(void *data, int count);

// 头插法
List headInsert(List list, Iterator node);

// 尾插法
List tailInsertNode(List list, Iterator node);

// 删除第index个节点
List removeindexNode(List list, int index);

// 删除值为key节点
List removekeyNode(List list, void *key, int count);

// 修改第index个节点
void *modifyNode(List list, int index);

//查找第index个节点
Iterator findindexNode(List list, int index);

//查找值为key的节点 //在节点begin到end范围
Iterator findkeyNode(List list, void *key, int count, int begin);

#endif