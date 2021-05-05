
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

//--------------------增 4

//创建无头链表
listnode *sinlinklist_creatlink(Item *data);

// 头插
listnode *sinlinklist_headinsert(listnode *link, Item *data);

//尾插
listnode *sinlinklist_pushlink(listnode *link, Item *data);

// 插入n点
listnode*sinlinklist_insertnnode(listnode*link, int where, Item* data);

//--------------------删 5

//头删
listnode *sinlinklist_headdel(listnode *link);

//尾删
listnode *sinlinklist_poplink(listnode *link);

//删除n点
listnode *sinlinklist_delnnode(listnode *link, int where);

//整表删不删item
void sinlinklist_delonlylink(listnode *link);

//删表删item
void sinlinklist_delalllink(listnode *link);

//-------------------改 1

//设置n点数据
listnode*sinlinklist_setnitem(listnode*link, int where, Item* data);

//-------------------查 2

//获取链表长度
int sinlinklist_getlenlink(listnode *link);

//获取n点
Item *sinlinklist_getnitem(listnode *link, int where);

//------------------其他 2

//非递归逆置（原地逆置）
listnode *sinlinklist_reslink(listnode *link);

//递归逆置
listnode *sinlinklist_reslink8(listnode *link);

#endif