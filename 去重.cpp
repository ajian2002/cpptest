#include <stdio.h>
#include <string.h>
int main()
{

	char b[100], d[100], c[26] = {0};
	char sp[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	int size, length;
	//scanf("%c",&sp);
	scanf("%s", &b);
	//	size=sizeof b;
	length = strlen(b);

	//	printf("%d\n%d\n",size,length);
	for (int i = 0; i < length; i++)
	{
		//	printf("%c\n",sp[26]);
		for (int ii = 0; ii < 26; ii++)
			if (b[i] == sp[ii])
			{
				c[ii]++;
				if (c[ii] == 2)
				{
					c[ii] = 1;
					b[i] = ' ';
				}
			}
	}
	int sum = 0, min = 0;
	for (int i = 0; i < length; i++)
	{
		sum++;
		if (b[i] == ' ' || i == length - 1)
		{
			if (sum >= min)
				min = sum;
			sum = 0;
		}
		sum = 0;
	}
	for (int i = 0; i < length; i++)
	{
		if (sum == min)
		{
			for (int f = min; f > 0; f--)
			{
				printf("%c", b[i - f]);
			}

			sum = 0;
		}
		if (b[i] == ' ' || i == length - 1)
			sum = 0;
		sum++;
	}
}
