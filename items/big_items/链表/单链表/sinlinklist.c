#include "sinlinklist.h"
#include <stdio.h>
#include <stdlib.h>

linklist *sinlinklist_creatlink(Item *data)
{
    listnode *frist = (listnode *)malloc(sizeof(listnode));
    linklist *link = (linklist *)malloc(sizeof(linklist));
    if (frist == NULL || link == NULL)
    {
        perror("creat failed\n");
        exit(-1);
    }
    frist->next = NULL;
    frist->item = data;
    link->head = frist;
    link->length = 1;

    return link;
}

linklist *sinlinklist_headinsert(linklist *llink, Item *data)
{

    if (llink == NULL)
    {
        perror("link not found");
        return llink;
    }
    listnode *link = llink->head;
    listnode *current = (listnode *)malloc(sizeof(listnode));
    if (current == NULL)
    {
        perror("malloc failed");
        return llink;
    }

    current->next = link;
    current->item = data;
    link = current;

    //struct Node ;
    llink->head = link;
    llink->length++;
    return llink;
}

linklist *sinlinklist_pushlink(linklist *llink, Item *data)
{
    if (llink == NULL)
    {
        perror("link not found");
        return llink;
    }
    listnode *link = llink->head;
    listnode *temp = (listnode *)malloc(sizeof(listnode));
    if (temp == NULL)
    {
        perror("malloc error");
        return llink;
    }
    if (link == NULL || llink->length == 0) //空头节点?
    {
        llink->length = 0;
        link = temp;
        link->item = data;
        link->next = NULL;
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
    }
    llink->head = link;
    llink->length++;
    return llink;
}

linklist *sinlinklist_insertnnode(linklist *llink, int where, Item *data)
{
    if (llink == NULL)
    {
        perror("link not found");
        return llink;
    }
    listnode *link = llink->head;

    if (where < 1 || where > llink->length + 1)
    {
        perror("invaild args");
        return llink;
    }
    else if (where == 1)
        return sinlinklist_headinsert(llink, data);
    else if (where == llink->length + 1)
        return sinlinklist_pushlink(llink, data);
    else
    {
        listnode *current = (listnode *)malloc(sizeof(listnode));
        if (current == NULL)
        {
            perror("malloc failed");
            return llink;
        }

        listnode *tailInsert = link;
        current->item = data;
        current->next = NULL;

        for (int i = 2; i < where; i++)
        {
            if (tailInsert && tailInsert->next)
            {
                tailInsert = tailInsert->next;
            }
            else
            {
                perror("insternnode error");
                free(current);
                return llink;
            }
        }

        current->next = tailInsert->next;
        tailInsert->next = current;
        llink->length++;
    }
    return llink;
}

linklist *sinlinklist_headdel(linklist *llink)
{
    if (llink == NULL)
    {
        perror("link not found");
        return llink;
    }
    listnode *link = llink->head;
    listnode *temp = link;
    if (link && llink->length > 0)
    {
        link = link->next;
        free(temp);
        llink->length--;
        llink->head = link;
    }
    else
    {
        perror("del error");
    }
    return llink;
}

linklist *sinlinklist_poplink(linklist *llink)
{
    if (llink == NULL)
    {
        perror("link not found");
        return llink;
    }
    listnode *link = llink->head;

    listnode *temp = link;
    if (temp == NULL || llink->length == 0)
    {
        perror("popnode error");
        return llink;
    }
    else if (llink->length == 1 || link->next == NULL)
    {
        if (link)
            free(link);
        llink->head = NULL;
        llink->length = 0;
        return llink;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    llink->length--;
    return llink;
}

linklist *sinlinklist_delnnode(linklist *llink, int where)
{

    if (llink == NULL)
    {
        perror("link not found");
        return llink;
    }
    listnode *link = llink->head;
    if (where < 1 || where > llink->length + 1)
    {
        perror("invaild args");
        return llink;
    }
    else if (where == 1)
        return sinlinklist_headdel(llink);
    else if (where == llink->length + 1)
        return sinlinklist_poplink(llink);
    else
    {
        listnode *temp = link;
        for (int i = 2; i < where; i++)
        {
            if (temp && temp->next)
            {
                temp = temp->next;
            }
            else
            {
                printf("delnode error");
                return llink;
            }
        }

        listnode *tt;
        tt = temp->next;
        //不太可能
        // if (tt == NULL)
        // {
        //     perror("delnode error");
        //     return llink;
        // }
        temp->next = temp->next->next;
        free(tt);
        llink->length--;
    }
    return llink;
}


int sinlinklist_delonlylink(linklist *llink)
{
    if (llink == NULL)
    {
        perror("link not found");
        return 0;
    }
    listnode *link = llink->head;
    while (link)
    {
        listnode *temp = link;
        if (link->next)
            link = link->next;
        else
        {
            free(link);
            llink->length--;
            break;
        }
        free(temp);
        llink->length--;
    }
    if (llink->length == 0)
    {
        llink->head = NULL;
        return 0;
    }
    else
    {
        return -1;
    }
}

int sinlinklist_delalllink(linklist *llink)
{
    if (llink == NULL)
    {
        perror("link not found");
        return -1;
    }
    listnode *link = llink->head;
    while (link && link->item)
    {
        listnode *temp = link;
        if (link->next)
            link = link->next;
        else
        {
            if (link->item)
                free(link->item);
            if (link)
                free(link);
            llink->length--;
            break;
        }
        if (temp->item)
            free(temp->item);
        if (temp)
            free(temp);
        llink->length--;
    }
    if (llink->length == 0)
    {
        llink->head = NULL;
        return 0;
    }
    else
        return -1;
}

/*

 TODO:reslink

linklist *sinlinklist_reslink8(linklist *llink)
{
    if (llink == NULL)
    {
        perror("link not found");
        return -1;
    }
    listnode *link = llink->head;
    if (!link || !link->next)
    {
        return llink;
    }
    listnode *temp = sinlinklist_reslink8(link->next); //temp是最后一项的指针
    link->next->next = link;
    link->next = NULL;
    return temp;
}

linklist *sinlinklist_reslink(linklist *llink)
{
    if (llink == NULL)
    {
        perror("link not found");
        return -1;
    }
    listnode *link = llink->head;
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
*/
Item *sinlinklist_getnitem(linklist *llink, int where)
{

    if (llink == NULL || llink->length == 0 || llink->head == NULL)
    {
        perror("link not found");
        return NULL;
    }
    listnode *link = llink->head;

    listnode *temp = link;
    if (where < 1 || where > llink->length)
    {
        perror("node not found");
        return NULL;
    }
    for (int i = 1; i < where; i++)
    {
        // printf("1\n");
        if (temp && temp->next)
        {
            temp = temp->next;
        }
        else
        {
            perror("getitem error\n");
            return NULL;
        }
    }
    return temp->item;
}

// int sinlinklist_getlenlink(linklist *llink)
// {
//     int count = 0;
//     while (link)
//     {
//         count++;
//         link = link->next;
//     }
//     return count;
// }

linklist *sinlinklist_setnitem(linklist *llink, int where, Item *data)
{
    if (llink == NULL)
    {
        perror("link not found");
        return llink;
    }
    listnode *link = llink->head;

    listnode *temp = link;
    if (where < 1 || where > llink->length)
    {
        perror("node not found");
        return NULL;
    }

    for (int i = 1; i < where; i++)
    {
        // printf("1\n");
        if (temp && temp->next)
        {
            temp = temp->next;
        }
        else
        {
            perror("getitem error\n");
            return llink;
        }
    }
    temp->item = data;
    return llink;
}
