#include <stdio.h>

#include <stdlib.h>
#include <string.h>
void gai(char **x, int x1, int y1, int x2, int y2, int length)
{
    if (x1 + 1 == x2 && y1 + 1 == y2)
    {
        *((char *)x + length * x1 + y1) = '0';
        *((char *)x + length * x1 + y2) = '1';
        *((char *)x + length * x2 + y1) = '1';
        *((char *)x + length * x2 + y2) = '1';
        return;
    }
    int temp1 = (x1 + x2) / 2;
    int temp2 = (y1 + y2) / 2;
    for (int i = x1; i <= temp1; i++)
        for (int j = y1; j <= temp2; j++)
        {
            *((char *)x + length * i + j) = '0';
        }

    gai(x, x1, temp2 + 1, temp1, y2, length);
    gai(x, temp1 + 1, y1, x2, temp2, length);
    gai(x, temp1 + 1, temp2 + 1, x2, y2, length);
}
int main()
{
    int n;
    scanf("%d", &n);
    int l = 1;
    for (int i = 0; i < n; i++)
    {
        l *= 2;
    }
    char x[l][l];
    memset(&x[0][0], '1', l * l);
    gai((char **)x, 0, 0, l - 1, l - 1, l);
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            printf("%c ", x[i][j]);
        }
        printf("\n");
    }
}