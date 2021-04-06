#include <string.h>
#include<stdio.h>
#include<stdlib.h>
struct x {
	int a[21];
	double b;
	char c;
}x1;
struct y{
	char a[1];
	struct	{
		int a[21];
		double b;
		char c;
	}x1;
	int c;
}x2;
struct z{
	struct x x1;
   struct y x2;
}x3;   




int main(){
	printf("%ld\n",sizeof(x1));
	printf("%ld\n",sizeof(x2));
	printf("%ld\n",sizeof(x3));
}
