
#include <stdio.h>
int main()
{
    int i = 0;
    long long int t = 1;
    scanf("%d", &i);
    while (i <= 100)
    {
        i = i + 2;
        t = t * i;
    }
    printf("%d", t);
}