#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 56
struct item
{
    int a;
    char b[size];
    struct item *next;
};
char *s_gets(char *st, int n);
int main()
{
    struct item *head, *preNode, *current;
    head = NULL;
    int arr[size];
    int i = 0;
    while (s_gets(arr, sizeof(arr)) != NULL)
    {   
        current = (struct item *)malloc(sizeof(struct item));
        if(*(current)==NULL)
        return -1;
        if (head == NULL)
            head = current;
        else
            preNode->next = current;
        current->next = NULL;



        preNode = current;
    }
}
char *s_gets(char *st, int n) //处理单个输入
{
    char *re, *find;
    re = fgets(st, n, stdin);
    if (re)
    {
        find = strchr(st, '\n');
        if (find)
        {
            *find = 0;
        }
        else
        {
            while (getchar() != 0)
                continue; //处理输出
        }
    }
    return re;
}