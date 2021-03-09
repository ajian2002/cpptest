#include "Double-circular-list.h"

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
#define num 10
//函数接口


int main()
{
    struct list *one = NULL;
    int a[15];
    for (int i = 0; i < 15; i++)
        a[i] = i;
    char *str[16] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o"};

    initList(&one, initNode(&a[1], sizeof(int)));
    headInsertNode(one, initNode(&a[1], sizeof(int)));
    tailInsertNode(one, initNode(&a[2], sizeof(int)));
    //seeintdata(one);
    printf("-----------------\n");
    //removekeyNode(one, &a[1], sizeof(int));
    //removekeyNode(one, &a[2], sizeof(int));
    //removeindexNode(one,3);
    //seeintdata(one);
    printf("-----------------\n");

    removeList(&one);
    return 0;
}
/*//查看void*  int
extern struct list;
void seedata(struct list *list)
{
    int len = list->length;
    struct node *temp = list->head;
    for (int i = 0; i < len; i++)
    {
        printf("%d :%d\n", i, *(int *)(temp->data));
        temp = temp->next;
    }
}*/