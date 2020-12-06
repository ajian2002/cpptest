#include <stdio.h>
#include <stdlib.h>
struct V {
	void *data;   //任意长度
	int elemSize; //每个元素大小
	struct V *next;
};
void push(struct V **newlinkList, void *data, int size) { //增加
	struct V *link = *newlinkList;
	//printf *newlinkList = link;
	//*newlinkList = link;
	//link = *newlinkList;
	while (link->next != NULL)
		link = link->next;

	//printf("1");
	struct V *temp = (struct V *)malloc(sizeof(struct V));
	link->next = temp;
	//for (int i = 0; i < size; i++)
	//  *(((char *)(temp->data) + i)) = (*(char *)(data) + i);
	temp->data = data;
	//printf("1");
	temp->elemSize = size;
	temp->next = NULL;
	//  return
	// *newlinkList = link1;
}
void pop(struct V **newlinkList, int size) { //删除
	struct V *link;
	link = *newlinkList;
	while (link->next->next != NULL)
		link = link->next;
	free(link->next);
	link->next = NULL;
}
int main() {
	//初始化结构体
	struct V **newlinkList;
	struct V *link = (struct V *)malloc(sizeof(struct V));
	*newlinkList = link;
	// *(double *)(link->data) = 2.1;
	double x1 = 2.1;
	link->data = &x1;
	link->elemSize = sizeof(x1);
	link->next = NULL;
	//增添删除操作
	char x2 = 'x';
	push(newlinkList, &x2, sizeof(x2));
	printf("%.2f ", *(double *)((*newlinkList)->data));
	printf("%c \n", *(char *)((*newlinkList)->next->data));
	pop(newlinkList, sizeof(char));

	printf("%.2f ", *(double *)((*newlinkList)->data));
	if (((*newlinkList)->next) != NULL)
		printf("%c \n", *(char *)((*newlinkList)->next->data));
	else
		printf("okk");
	// printf("1");
	free(newlinkList);
	return 0;
}
