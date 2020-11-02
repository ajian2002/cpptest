#include <stdio.h>
#include <string.h>
int main()
{

	char b[26], sp;
	int size, length;
	scanf("%c", &sp);
	scanf("%s", b);
	//	size=sizeof b;
	length = strlen(b);
	//	printf("%d\n%d\n",size,length);
	for (int i = 0; i < length; i++)
	{
		//printf("%c\n",b[i]);
		if (b[i] == sp)
		{
			printf("%d", i + 1);
			break;
		}
	}
}
