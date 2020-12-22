#include <stdio.h>
#include <stdlib.h>

typedef struct linkstack
{
    int data;
    struct linkstack *next;
};

void *init_linkstack(int size)
{
    linkstack *S = (linkstack *)malloc(size * sizeof(linkstack));
    linkstack *temp = S;
    for (int i = 0; i < size - 1; i++)
        temp = temp->next;
    temp->next = NULL;
    if (S)
        return S;
    else
        printf("ERROR\n");
}
void del_linkstack(linkstack *S)
{
    while (S)
    {
        linkstack *temp = S;
        S = S->next;
        free(temp);
    }
}
void pop_linkstack(linkstack *S)
{
    if (S->next && S)
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
void push_linkstack(linkstack *S, int elem)
{
    linkstack *temp = S;
    if (S == NULL)
    {
        S = (linkstack *)malloc(sizeof(linkstack));
        S->data = elem;
        S->next = NULL;
    }
    else
    {
        while (S->next != NULL)
            S = S->next;
        temp = (linkstack *)malloc(sizeof(linkstack));
        temp->data = elem;
        temp->next = NULL;
        S->next = temp;
    }
}
void see_linkstack(linkstack *S)
{
    if (S == NULL)
    {
        printf("空\n");
    }
    else
    {
        linkstack *temp = S;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
