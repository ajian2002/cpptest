#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    char name[9];
    int y;
    int s;
    int e;
    int sum;
} s;
int main()
{
    int n;
    scanf("%d", &n);
    s a[n + 1];
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d%d%d", a[i].name, &a[i].y, &a[i].s, &a[i].e);
        a[i].sum = a[i].y + a[i].s + a[i].e;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(a[i].sum - a[j].sum) < 11)
            {
                if (abs(a[j].y - a[i].y) < 6)
                {
                    if (abs(a[j].s - a[i].s) < 6)
                    {
                        if (abs(a[j].e - a[i].e) < 6)
                        {
                            printf("%s %s\n", a[i].name, a[j].name);
                        }
                    }
                }
            }
        }
    }
}