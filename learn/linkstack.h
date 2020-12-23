#include <stdio.h>
#include <stdlib.h>
struct linkstack
{
    int data;
    struct linkstack *next;
};

void *init_stack(int frist)
{
    struct linkstack *S = (struct linkstack *)malloc(sizeof(struct linkstack));
    if (S)
    {
        S->data = frist;
        S->next = NULL;

        return S;
    }
    else
        printf(" creat ERROR\n");
}
void del_stack(struct linkstack *S)
{
    while (S)
    {
        struct linkstack *temp = S;
        S = S->next;
        free(temp);
    }
}
void pop_stack(struct linkstack *S)
{
    if (S->next)
    {
        while (S->next->next != NULL)
        {
            S = S->next;
        }
        int temp = S->next->data;
        free(S->next);
        S->next = NULL;
        return temp;
    }
    else if (S)
    {
        int temp = S->data;
        free(S);
        return temp;
    }
    else
    {
        printf("弹栈出错\n");
    }
}
void push_stack(struct linkstack *S, int elem)
{
    struct linkstack *temp1 = S;
    if (1)
    {
        while (temp1->next != NULL)
            temp1 = temp1->next;
        struct linkstack *temp = (struct linkstack *)malloc(sizeof(struct linkstack));
        temp->data = elem;
        temp->next = NULL;
        temp1->next = temp;
    }
}
void see_stack(struct linkstack *S)
{
    if (S == NULL)
    {
        printf("空\n");
    }
    else
    {
        struct linkstack *temp = S;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
