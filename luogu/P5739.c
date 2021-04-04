#include <stdio.h>
int jei(int x)
{
    if (x == 0 || x == 1)
        return 1;
    return x * jei(x - 1);
}
int main()
{
    int x;
    scanf("%d", &x);
    printf("%d", jei(x));
}