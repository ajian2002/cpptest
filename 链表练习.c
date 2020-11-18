#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 256
/*typedef struct LINKTABLE
{
    int elem_count;
    struct LINKTABLE *NEXT;
} linktable;
*/
struct A
{
    char s[8];
    int xc;
};
struct B
{
    struct A sd;
    char ss;
    int xcc;
};

struct film
{
    char title;
    int paper;
    struct film *next;
};

int main(int argc, char *argv[])
{
    struct film *head = NULL;
    struct film *preNode, *current;
    char get[SIZE];
    int i = 0;
    while (scanf("%c", &get[i]) && get[i] != '\n')
    {
        //printf("%d ", i);
        //创建节点
        current = (struct film *)malloc(sizeof(struct film));
        if (head == NULL)   //第一
            head = current; //头指当前
        else
            preNode->next = current; //上一个尾指过来
        current->next = NULL;        //这个尾设置空
        current->title = get[i++];

        preNode = current; //在最后面传递下去
    }
    if (head == NULL)
    {
        printf("0");
        return 0;
    }
    current = head;
    while (current != NULL)
    {
        //重新指向头
        printf("%c", current->title);
        current = current->next;
    }
    current = head;

    while (head != NULL)
    {
        current = head;
        head = current->next;
        free(current);
        //printf("%d", i++);
    }

    printf("1");
    /* struct A C[2] =
        {
            {"sfdsd", //char [8]
             23},     //int
            {"ssd",
                85}};
    struct B C2[2] =
        {
            {{"sfdsd", 23},
                's',
                234},
            {{"ssd", 85},
                'q',
                44}};
    struct A *de;
    de = &C[0];
    printf("%s", de->s);
    struct B *sfx = &C2[0];
    printf("%d\n", sfx->xcc);

    char chars[2];
    int x, y;
*/
    //sfx->
    //  printf("%p %p %p\n", &x, &chars[0], sfx + 2);
    // printf("%p %p \n", &C[0], &C[1];
    //printf("%p %p", de, de + 1);

    //return 0;
}