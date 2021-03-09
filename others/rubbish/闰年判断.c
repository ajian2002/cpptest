#include <stdio.h>
int RUNNIAN(int year)
{
	int IF;

	if (year % 100 == 0)
	{
		if (year % 400 == 0)
			IF = 1;
		else
			IF = 0;
		goto cww;
	}
	else if (year % 4 == 0)
		IF = 1;
	else
		IF = 0;
cww:
	return IF;
}
int main()
{

	int IF = RUNNIAN(1900);
	if (IF)
		printf("YES");
	else
	{
		printf("NO");
	}
}