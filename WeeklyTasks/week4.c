#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    charr = 1,
    strings = 10,
    intt = 4,
    doublee = 8,
    voidd = 0
} type;

typedef union
{
    char data1;
    int data4;
    char *data10;
    void *data0;
} un;

typedef struct node
{
    struct node *next;
    void *data;
    type tt;
} N;

void *add(N *head, void *data, type ty, int size)
{
    N *temp = head;
    N *zz = NULL;
    int count = 0;

    if (head == NULL)
    {
        head = (N *)malloc(sizeof(N));
        head->next = NULL;
        temp = head;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                zz = temp;
            }
            temp = temp->next;
        }
        temp = (N *)malloc(sizeof(N));
        zz->next = temp;
        temp->next = NULL;
    }

    switch (ty)
    {
        if (sdw == NULL)
            data = sdw;
    case 4:
        temp->data = data;
        temp->tt = 4;
        break;
    case 1:
        temp->data = data;
        temp->tt = 1;
        break;
    case 0:
        //24//
        // printf("%ld", sizeof(*(N *)data));

        //24   24   48
        //void*data   next,data,ty
        //N *hh = (N *)data;
/*
        for (int i = 0; i < size; i++)
        {
            N *hh = (N *)data + i;
            ((N *)data)->tt = hh->tt;
            head = add(head, hh, hh->tt, 0);
        }
        break;
        //free(temp);
        /*zz = temp;
        temp->data =data[0]->data;
        zz->next = temp;
        zz->tt = temp->tt;
        
        //  while (temp->next != NULL)
    }
    if (size != count)
    {
        count++;
        head = add(head, (N *)data + count, ((N *)data + count)->tt, 0);
    }
    else
    {
        count = 0;
    }
*/
    return head;
}
void see(N *head)
{
    N *temp = head;
    while (temp != NULL)
    {
        switch (temp->tt)
        {
        case 4:
            printf("%d ", *(int *)(temp->data));
            break;
        case 1:
            printf("%c ", *(char *)(temp->data));
            break;
        case 0:
            see(temp);
        }
        temp = temp->next;
    }
    printf("\n");
}
void del(N *head)
{
    N *temp = NULL;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main()
{
    //char *s = "[4,'c',[4,'c']]"
    N *head = NULL;

    un d[10];
    d[0].data4 = 4;
    d[1].data1 = 'c';
    N nn[2] = {{&nn[1], &d[0].data4, 4}, {NULL, &d[1].data1, 1}}; //24*2
    //d[2].data0 = &nn;
    head = add(head, &d[0].data4, 4, 0);
    see(head);
    head = add(head, &d[1].data1, 1, 0);
    see(head);
    head = add(head, &nn, 4, 2);
    see(head);
    del(head);
}
