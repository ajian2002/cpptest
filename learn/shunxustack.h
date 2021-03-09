#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
//顺序存储结构 栈的基本操作
typedef struct
{
    int data[MAXSIZE];
    int top;
} shunstack;
//初始化一个空栈
void *init_stack(void)
{
    shunstack *S = (shunstack *)malloc(sizeof(shunstack));
    S->top = -1;
    return S;
}
//销毁
void del_stack(shunstack *S)
{
    if (S != NULL)
        free(S);
}
//清空
void clr_stack(shunstack *S)
{
    if (S != NULL)
        S->top = -1;
}
//判断是否为空
int isclr_stack(shunstack *S)
{
    if (S == NULL)
        return -1;
    if (S->top == -1)
        return 1;
    else
        return 0;
}

//返回栈顶元素
int get_top(shunstack *S)
{
    if (S->top > -1)
        return S->data[S->top];
    else if (S->top == -1)
    {
        printf("\r栈空");
        return -1;
    }
}
//入栈
void push_stack(shunstack *S, int elem)
{
    if (S != NULL)
    {
        if (S->top < MAXSIZE - 1)
        {
            S->top++;
            S->data[S->top] = elem;
        }
        else
        {
            printf("boom\n");
        }
    }
}

//出栈  返回元素
int pop_stack(shunstack *S)
{
    if (S->top < 0)
    {
        printf("stack black\n");
    }
    else
    {
        printf("%d\n", S->data[S->top]);
        if (S->top - 1 < 0)
            printf("stack black\n");
        return S->data[S->top--];
    }
    return -1;
}
//获取个数
int len_stack(shunstack *S)
{
    if (S->top > -1 && S->top < MAXSIZE)
        return S->top + 1;
    else
        return 0;
}
//查看栈
void see_stack(shunstack *S)
{
    if (S->top == -1)
    {
        printf("kong stack\n");
        return;
    }
    for (int i = 0; i < S->top; i++)
    {
        printf("%d ", S->data[i]);
    }
    printf("%d", S->data[S->top]);
    printf("\n");
}
