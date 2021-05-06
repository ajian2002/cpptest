
//无头单链表
#ifndef MYLISTNODE
#define MYLISTNODE
// struct Date
// {
//     int intdata;
//     void *voiddata;
// };
typedef struct Date Item;

struct ListNode
{
    Item *item;
    struct ListNode *next;
    //  struct node *prev;
};
typedef struct ListNode listnode;
struct LinkList
{
    listnode *head;
    int length ;
    // pthread_mutex_t mutex;
    // pthread_cond_t cond;
};
typedef struct LinkList linklist;
//--------------------增 4

//创建无头链表
linklist *sinlinklist_creatlink(Item *data);

// 头插
linklist *sinlinklist_headinsert(linklist *llink, Item *data);

//尾插
linklist *sinlinklist_pushlink(linklist *llink, Item *data);

// 插入n点
linklist *sinlinklist_insertnnode(linklist *llink, int where, Item *data);

//--------------------删 5

//头删
linklist *sinlinklist_headdel(linklist *llink);

//尾删
linklist *sinlinklist_poplink(linklist *llink);

//删除n点
linklist *sinlinklist_delnnode(linklist *llink, int where);

//整表删不删item
int sinlinklist_delonlylink(linklist *llink);

//删表删item
int sinlinklist_delalllink(linklist *llink);

//-------------------改 1

//设置n点数据
linklist *sinlinklist_setnitem(linklist *llink, int where, Item *data);

//-------------------查 2

// //获取链表长度
// int sinlinklist_getlenlink(linklist *llink);

//获取n点
Item *sinlinklist_getnitem(linklist *llink, int where);

//------------------其他 2

//非递归逆置（原地逆置）
linklist *sinlinklist_reslink(linklist *llink);

//递归逆置
linklist *sinlinklist_reslink8(linklist *llink);

#endif