#include <stdio.h>
#define LEN 1024
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
struct DD
{
	int Int;
};
struct str
{
	struct DD data;
	struct str *next;
	struct str *prev;
};

char **infix_to_suffix(char **infix, int *llen) //中缀转后缀
{
	int len = *llen;
	*llen = 0;
	return NULL;
	



}

int evalRPN(char **tokens, int tokensSize) //后缀求值
{
	//链栈
	// printf("%d\n", tokensSize);
	if (tokensSize < 1)
	{
		perror("size is zero ");
		exit(-1);
	}
	struct str *head = (struct str *)malloc(sizeof(struct str));
	struct str *temp = head;
	temp->prev = NULL;
	temp->next = NULL;
	temp->data.Int = 0;
	char *a = "+-*/";
	int len = tokensSize;
	for (int i = 0; i < len; i++)
	{
		if (strlen(tokens[i]) == 1 && strpbrk(tokens[i], a) != NULL)
		{
			if (strcmp(tokens[i], "+") == 0)
			{
				temp->prev->data.Int += temp->data.Int;
			}
			else if (strcmp(tokens[i], "-") == 0)
			{
				temp->prev->data.Int -= temp->data.Int;
			}
			else if (strcmp(tokens[i], "*") == 0)
			{
				temp->prev->data.Int *= temp->data.Int;
			}
			else if (strcmp(tokens[i], "/") == 0)
			{
				temp->prev->data.Int /= temp->data.Int;
			}
			temp = temp->prev;
			free(temp->next);
			temp->next = NULL;
			head->data.Int -= 1;
		}
		else //数字
		{
			if (temp->next == NULL)
			{
				temp->next = (struct str *)malloc(sizeof(struct str));
				head->data.Int += 1;
				temp->next->prev = temp;
				temp = temp->next;
				temp->next = NULL;
				temp->data.Int = atoi(tokens[i]);
			}
		}
	}
	int result = head->next->data.Int;

	free(head->next);
	free(head);
	return result;
}

int main(void)
{
	int len = 5;
	char *str1[5] = {"1", "+", "3", "-", "5"}; //13+5-
	char *str2[5] = {"1", "3", "+", "5", "-"};
	printf("%d\n", evalRPN(str2, 5));
	char **str3 = infix_to_suffix(str1, &len);
	printf("%d\n", evalRPN(str3, len));
	//((传地址-改返回),(传值))

	return 0;
}
