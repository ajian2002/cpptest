//##全局变量max,mid,min##

//```
#include <stdio.h>
//int max, mid, min;
void MAXMIN(int *a, int *b, int *c)
{
    int max, min, mid;
    max = *a;
    min = *a;
    if (max < *b)
        max = *b;
    if (max < *c)
        max = *c;
    if (min > *b)
        min = *b;
    if (min > *c)
        min = *c;
    mid = *a + *b + *c - max - min;
    *a = max;
    *b = mid;
    *c = min;
    //   printf("%p \n%p\n%p",&a,&b,&c);
    //  printf("%d\n%d\n%d\n",a,b,c);
}

//```
int main()
{
    int a, b, c;
    printf("raas a,b,c");
    scanf("%d%d%d", &a, &b, &c);
    MAXMIN(&a, &b, &c);
    printf("s:%d %d %d", a, b, c);

    return 0;
}
