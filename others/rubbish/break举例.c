#include <stdio.h>
int main()
{
    for (int i = 0; i < 10; i++)
    {
        if (i != 3)
            printf("%d\n", i);
        else
            break;
    }
}