#include <stdio.h>
#include <conio.h>

int main()
{ //实现读入一个字符，输出getch的返回值码
	int ch;
	while (1)
	{
		while (ch = getch()) //把得到的值赋值给ch
		{
			printf("%d", ch); //依次输入 a b c d ↑↓ ← →
		}
		printf("\n");
	}
	return 0;
}
/*
#include <readline/readline.h>
int main()
{
	char *c;
	c=readline("123");
	printf("%s", c);
}
*/