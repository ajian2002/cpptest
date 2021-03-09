#include <stdio.h>
#include "/home/ajian/code/cpptest/learn/shunxustack.h"
#define LEN 1024
void infix_to_suffix(char*infix, char*suffix)
{

}
int main(void)
{
	char *s1 = (char *)malloc(sizeof(char) * LEN);
	memset(s1, 0, sizeof(char) * LEN);
	scanf("%s", sq);
	char *s2 = (char *)malloc(sizeof(char) * LEN);
	memset(s2, 0, sizeof(char) * LEN);
	infix_to_suffix(s1,s2);
	calculation();
	free(s1);
	free(s2);
	return 0;
}
