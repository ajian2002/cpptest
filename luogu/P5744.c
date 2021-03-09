#include <stdio.h>
typedef struct
{
    char name[20];
    int age;
    int sum;
} node;

node *dep(node *a)
{
    a->age++;
    a->sum = (a->sum) * 1.2;
    if (a->sum > 600)
        a->sum = 600;
}
int main()
{
    int n;
    scanf("%d", &n);
    node student[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d%d", student[i].name, &student[i].age, &student[i].sum);

        dep(&student[i]);

        printf("%s %d %d\n", student[i].name, student[i].age, student[i].sum);
    }
}