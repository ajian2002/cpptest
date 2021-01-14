#include <stdio.h>
int main()
{
    //printf("hello world");
    //  return 0;
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d", (int *)(a + 4));
}