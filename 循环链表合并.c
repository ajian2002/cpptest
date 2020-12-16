#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} belink;
void *creaklink(void) //无头
{
    belink *frist = (belink *)malloc(sizeof(belink));
    if (frist == NULL)
    {
        printf("creat failed");
        exit(0);
    }
    frist->next = NULL;
    return frist;
}
int main()
{
    //创建循环链表
    belink *one = creaklink();
    one->data = 1;
    one->next = creaklink();
    one->next->data = 2;
    one->next->next = creaklink();
    one->next->next->data = 3;
    one->next->next->next = one;
    belink *two = creaklink();
    two->data = 4;
    two->next = creaklink();
    two->next->data = 5;
    two->next->next = creaklink();
    two->next->next->data = 6;
    two->next->next->next = two;
    //循环链表的合并
    
}