#include <stdio.h>
#include <stdbool.h>
int main(void)
{
	int a = 1;

	int *p = &a;

	//printf("%d\n", *p);
	//printf("%d", a);

	int arr[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = 0;
	//*arr[10] = *arr + *(arr + 1);
	printf("arr[11]    sum\n");
	printf("sum %p\n", &sum);
	printf("arr %p\n", &arr);
	printf("arr[-1] %p\n", &arr[-1]);
	printf("arr[11] %p\n", &arr[11]);

	printf("\n");
	int sum1 = 0;
	int arr1[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	//*arr[10] = *arr + *(arr + 1);
	printf("sum1   arr[11]\n");
	printf("sum1 %p\n", &sum1);
	printf("arr1 %p\n", &arr1);
	printf("arr1[-1] %p\n", &arr1[-1]);
	printf("arr1[11] %p\n", &arr1[11]);
}
