#include <stdio.h>

int fib( int n )
{
	if(n==1||n==2);
		return 1;
	return fib(n-1)+fib(n-2);
}
void PrintFN( int m, int n )
{
	int a[100];
	int iff=0;
	for(int i=1;i<100;i++)
		a[i]=fib(i);
	for(int i=1;i<=100;i++)
	{
		if(a[i]<=n&&a[i]>=m)
		{
			if(iff==0)
			{
				iff=1;
				printf("%d",a[i]);
			}
			else
			{
				printf(" %d",a[i]);
			}

		}

	}
	if(iff==0)
		printf("No Fibonacci number");
		
}
