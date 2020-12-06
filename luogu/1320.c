
#include <stdio.h>
int main(int argc, char argv[])
{
    char c;
    int line = 0;
    int i = 0;
    int a[100000] = {0};
    int b[1000] = {0};
    scanf("%c", &c);
    int z = 0;
    while (c == '0' || c == '1')
    {
        while (c == '0' || c == '1')
        {

            a[i] = c - '0';
            i++;
            z++;

            scanf("%c", &c);
            if (c == '\r')
                scanf("%c", &c);
        }
        line++;
        if (line == z)
            break;
        z = 0;
        scanf("%c", &c);
        if (c == '\r')
            scanf("%c", &c);
    }
    printf("%d", line);
    //i = 个数
    int sum = 0;
    int x = 1;
    int this = 0;
    while (sum < i)
    {
        if (a[0] != 0 && this == 0)
        {
            printf(" 0");
            this = 1;
        }
        if (a[sum] != a[sum + 1])
        {
            printf(" %d", x);
            x = 0;
        }
        x++;
        sum++;
        //printf("xxx\n");
    }
    printf(" \n");
    printf("%d", sum);
}
//printf("1");
//printf("%c", c);
