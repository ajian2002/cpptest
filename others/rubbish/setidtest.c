#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int n, find;
	scanf("%d", &n);
	int a[n];
	int dount = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &find);
	int iss = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < find && iss == 0)
		{

			printf("%3d", find);
			iss = 1;
		}
		printf("%3d", a[i]);
	}
	if (a[n - 1] > find)
	{
		printf("%3d", find);
	}
}
