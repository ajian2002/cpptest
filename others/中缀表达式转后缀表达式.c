#include <stdio.h>
#define LEN 1024
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
struct DD
{
	int Int;
	char Char[2];
	int level;
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
	int templen = 0;

	struct str *head = (struct str *)malloc(sizeof(struct str));
	struct str *temp = head;
	temp->prev = NULL;
	temp->next = NULL;
	strcpy(temp->data.Char, "(");

	char **sum = (char **)malloc(len * sizeof(char *)); //假设有这么多转换后的字符
	for (int i = 0; i < len; i++)
	{
		sum[i] = (char *)malloc(10 * sizeof(char));
		memset(sum[i], 0, 10 * sizeof(char));
	}

	int j = 0;
	for (int i = 0; i < len; i++)
	{
		templen = strlen(infix[i]);
		if (templen)
		{
			if (strcmp(infix[i], "+") == 0 || strcmp(infix[i], "-") == 0)
			{
				if (temp->prev == NULL || strcmp(temp->data.Char, "(") == 0) //存 ( 或者 NULL
				{

					temp->next = (struct str *)malloc(sizeof(struct str));
					temp->next->prev = temp;
					temp = temp->next;
					temp->next = NULL;
					strcpy(temp->data.Char, infix[i]);
				}
				else //输出
				{

					strcpy(sum[j++], temp->data.Char);
					strncpy(temp->data.Char, infix[i], 2);
				}
			}
			else if (strcmp(infix[i], "*") == 0 || strcmp(infix[i], "/") == 0)
			{
				if (strcmp(temp->data.Char, "*") == 0 || strcmp(temp->data.Char, "/") == 0)
				{

					strcpy(sum[j++], temp->data.Char);
					strncpy(temp->data.Char, infix[i], 2);
				}
				else
				{
					temp->next = (struct str *)malloc(sizeof(struct str));
					temp->next->prev = temp;
					temp = temp->next;
					temp->next = NULL;
					strcpy(temp->data.Char, infix[i]);
				}
			}
			else if (strcmp(infix[i], "(") == 0)
			{
				temp->next = (struct str *)malloc(sizeof(struct str));
				temp->next->prev = temp;
				temp = temp->next;
				temp->next = NULL;
				strcpy(temp->data.Char, infix[i]);
			}
			else if (strcmp(infix[i], ")") == 0)
			{

				while (strcmp(temp->data.Char, "(") != 0)
				{
					strcpy(sum[j++], temp->data.Char);
					temp = temp->prev;
					free(temp->next);
					temp->next = NULL;
				}
				temp = temp->prev;
				free(temp->next);
				temp->next = NULL;
			}
			else
			{
				//			int data = atoi(infix[i]);
				strcpy(sum[j++], infix[i]);

				/*
			temp->next = (struct str *)malloc(sizeof(struct str));
			temp->next->prev = temp;
			temp = temp->next;
			temp->next=NULL;
			temp->data.Int = data;
			*/
			}
		}
	}
	//	last one

	while (strcmp(temp->data.Char, "(") != 0)
	{
		strcpy(sum[j++], temp->data.Char);
		temp = temp->prev;
		free(temp->next);
		temp->next = NULL;
	}
	free(temp);
	head = NULL;
	*llen = j;
	return sum;
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
			if (head->data.Int == 0)
			{
				perror("first error ");
				exit(1);
			}
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
	int len = 15;
	char *str1[15] = {"1", "+", "(", "3", "-", "5", "*", "2", ")", "/", "2", "+", "4", "*", "6"}; //13+5-
	char *str2[5] = {"1", "3", "+", "5", "-"};
	//printf("%d\n", evalRPN(str2, 5));
	char **str3 = infix_to_suffix(str1, &len);
	printf("%d\n", evalRPN(str3, len));
	//((传地址-改返回),(传值))

	return 0;
}
