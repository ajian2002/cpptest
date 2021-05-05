#include "sinlinklist.h"
#include <stdio.h>
#include <stdlib.h>

listnode *sinlinklist_creatlink(Item *data)
{
    listnode *frist = (listnode *)malloc(sizeof(listnode));

    if (frist == NULL)
    {
        perror("creat failed\n");
        exit(-1);
    }

    frist->next = NULL;
    frist->item = data;
    return frist;
}

listnode *sinlinklist_headinsert(listnode *link, Item *data)
{
    listnode *current;
    current = (listnode *)malloc(sizeof(listnode));
    if (current == NULL)
    {
        perror("malloc failed");
        exit(-1);
    }
    else
    {
        current->next = link;
        current->item = data;
        return current;
        //struct Node ;
    }
}

listnode *sinlinklist_pushlink(listnode *link, Item *data)
{
    listnode *temp = (listnode *)malloc(sizeof(listnode));
    if (temp == NULL)
    {
        perror("malloc error");
        exit(-1);
    }
    if (link == NULL) //空头节点?
    {
        link = temp;
        link->item = data;
        link->next = NULL;
        return link;
    }
    else //找到末尾
    {

        temp->next = NULL;
        temp->item = data;
        //找到最后一项
        listnode *find = link;
        while (find->next != NULL)
        {
            find = find->next;
        }

        find->next = temp;
        return link;
    }
}

listnode *sinlinklist_insertnnode(listnode *link, int where, Item *data)
{
    listnode *current = NULL;
    current = (listnode *)malloc(sizeof(listnode));
    if (current == NULL)
    {
        perror("malloc failed");
        exit(-1);
    }
    current->item = data;
    current->next = NULL;
    listnode *tailInsert = link;

    if (current == NULL || data == NULL || where < 1)
    {
        printf("invaild args\n");
        return link;
    }
    else
    {
        if (where == 1)
        {
            current->next = link;
            return current;
        }
        else
        {

            for (int i = 2; i < where; i++)
            {
                if (tailInsert)
                {
                    tailInsert = tailInsert->next;
                }
                else
                {
                    printf("insternnode error");
                    exit(-1);
                }
            }

            current->next = tailInsert->next;
            tailInsert->next = current;
            return link;
        }
    }
    return link;
}

listnode *sinlinklist_headdel(listnode *link)
{
    listnode *temp = link;
    if (link->next)
    {
        link = link->next;
        free(temp);
        return link;
    }
    else
    {
        return NULL;
    }
}

listnode *sinlinklist_poplink(listnode *link)
{
    listnode *temp = link;
    if (temp == NULL || temp->next == NULL)
    {
        perror("popnode error");
        exit(-1);
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return link;
}

Item *sinlinklist_getnitem(listnode *link, int where)
{
    listnode *temp = link;
    for (int i = 1; i < where; i++)
    {
        // printf("1\n");
        if (temp)
        {
            temp = temp->next;
        }
        else
        {
            perror("getitem error\n");
            exit(-1);
        }
    }
    if (temp && temp->item)
        return (temp->item);
    else
    {
        perror("getitem error");
        exit(-1);
    }
}

listnode *sinlinklist_delnnode(listnode *link, int where)
{

    listnode *temp = link;
    if (temp == NULL || temp->next == NULL)
    {
        perror("deldata error");
        exit(-1);
    }

    if (where == 1)
    {
        temp = link->next;
        free(link);
        return temp;
    }
    else
    {
        for (int i = 2; i < where; i++)
        {
            if (temp)
            {
                temp = temp->next;
            }
            else
            {
                printf("delnode error");
                exit(-1);
            }
        }

        listnode *tt;
        tt = temp->next;
        if (tt == NULL)
        {
            perror("delnode error");
            exit(-1);
        }
        temp->next = temp->next->next;
        free(tt);
    }
    return link;
}

void sinlinklist_delonlylink(listnode *link)
{
    while (link)
    {
        listnode *temp = link;
        if (link->next)
            link = link->next;
        else
        {
            free(link);
            return;
        }
        free(temp);
    }
    free(link);
}

void sinlinklist_delalllink(listnode *link)
{
    while (link && link->item)
    {
        listnode *temp = link;
        if (link->next)
            link = link->next;
        else
        {
            free(link->item);
            free(link);
            return;
        }
        free(temp->item);
        free(temp);
    }
    free(link->item);
    free(link);
}

listnode *sinlinklist_reslink8(listnode *link)
{
    if (!link || !link->next)
    {
        return link;
    }
    listnode *temp = sinlinklist_reslink8(link->next); //temp是最后一项的指针
    link->next->next = link;
    link->next = NULL;
    return temp;
}

listnode *sinlinklist_reslink(listnode *link)
{
    if (!link || !link->next)
        return link;
    else
    {
        listnode *prev = NULL;
        listnode *now = link;
        listnode *xia = link->next;
        while (xia)
        {
            link->next = prev;
            prev = link;
            link = xia;
            xia = xia->next;
        }
        link->next = prev;
        return link;
    }
}

int sinlinklist_getlenlink(listnode *link)
{
    int count = 0;
    while (link)
    {
        count++;
        link = link->next;
    }
    return count;
}

listnode *sinlinklist_setnitem(listnode *link, int where, Item *data)
{
    listnode *temp = link;
    for (int i = 1; i < where; i++)
    {
        // printf("1\n");
        if (temp)
        {
            temp = temp->next;
        }
        else
        {
            perror("getitem error\n");
            exit(-1);
        }
    }
    if (temp && temp->item)
    {
        temp->item = data;
        return link;
    }
    else
    {
        perror("getitem error");
        exit(-1);
    }
}
