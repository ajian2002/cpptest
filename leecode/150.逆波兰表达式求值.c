/*
 * @lc app=leetcode.cn id=150 lang=c
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start

#include <string.h>
struct str
{
    int data;
    struct str *next;
    struct str *prev;
};

int evalRPN(char **tokens, int tokensSize)
{
    //链栈
    struct str *head = (struct str *)malloc(sizeof(struct str));
    struct str *temp = head;
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = 0;
    char *a = "+-*/";
    char *b = "0123456789";

    int len = tokensSize;
    for (int i = 0; i < len; i++)
    {
        if (strlen(tokens[i]) == 1)
        {
            if (strcmp(tokens[i], "+") == 0)
            {
                temp->prev->data += temp->data;
                temp = temp->prev;
                free(temp->next);
                temp->next = NULL;
                head->data -= 1;
            }
            else if (strcmp(tokens[i], "-") == 0)
            {
                temp->prev->data -= temp->data;
                temp = temp->prev;
                free(temp->next);
                temp->next = NULL;
                head->data -= 1;
            }
            else if (strcmp(tokens[i], "*") == 0)
            {
                temp->prev->data *= temp->data;
                temp = temp->prev;
                free(temp->next);
                temp->next = NULL;
                head->data -= 1;
            }
            else if (strcmp(tokens[i], "/") == 0)
            {
                temp->prev->data /= temp->data;
                temp = temp->prev;
                free(temp->next);
                temp->next = NULL;
                head->data -= 1;
            }
            else
            {
                goto wwc;
            }
        }
        else //数字
        {
        wwc:
            if (temp->next == NULL)
            {
                temp->next = (struct str *)malloc(sizeof(struct str));
                head->data += 1;
                temp->next->prev = temp;
                temp = temp->next;
                temp->next = NULL;
                temp->data = atoi(tokens[i]);
            }
        }
    }
    return head->next->data;
}
// @lc code=end
