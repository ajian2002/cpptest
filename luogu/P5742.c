#include <stdio.h>
typedef struct
{
    int number;
    int s1;
    int s2;
    double sum;
} node;
int getsum1(node a)
{
    return a.s1 + a.s2;
}
int isexcellent(node a)
{
    if (a.sum >= 80)
    {
        if (getsum1(a) > 140)
            return 1;
    }
    return 0;
}
int main()
{

    int n;
    scanf("%d", &n);
    node student[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &student[i].number, &student[i].s1, &student[i].s2);
        student[i].sum = 0.7 * student[i].s1 + 0.3 * student[i].s2;
        if (isexcellent(student[i]))
            printf("Excellent\n");
        else
            printf("Not excellent\n");
    }
}