#include <stdio.h>
#include <math.h>
int main()
{
    double hour = 0, minute = 0;
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = ", a, b);
    if (a % b == 0)
        printf("%d", a / b);
    else
    printf("%.2f", (a * 1.00 / b * 1.00));
}