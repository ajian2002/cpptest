#include <stdio.h>
int main()
{
    volatile int a = 10;
    const int b = 9;
    volatile const int c = 8;
    // restrict
    printf("%d,%d,%d", a, b, c);
}