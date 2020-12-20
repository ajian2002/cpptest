#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
//顺序存储结构 栈的基本操作
typedef struct
{
    int data[MAXSIZE];
    int top;
}stack;
//初始化
void* init_stack(void*head, int size);

//销毁

//清空

//判断是否为空

//返回栈顶元素

//入栈

//出栈  返回元素

//获取个数

//查看栈
