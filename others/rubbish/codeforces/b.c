#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x;
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        int c;
        scanf("%d", &c);
        int p[c];
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &p[j]);
        }
        int book[51] = {0};
        int count = 0;
        for (int m = 0; m < c - 1; m++)
        {
            for (int z = m + 1; z < c; z++)
            {
                if (book[abs(p[m] - p[z])] == 0)
                {
                    book[abs(p[m] - p[z])] = 1;
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }
}