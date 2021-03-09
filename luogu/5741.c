#include <stdio.h>
#include <stdlib.h>
struct stu
{
    char name[100];
    int a;
    int b;
    int c;
};
int main()
{
    int n;
    scanf("%d", &n);
    struct stu student[n + 1];
    for (int i = 1; i <= n; i++)
    {
        sscanf(stdin, "%s %d %d %d\n", student[i].name, &student[i].a, &student[i].b, &student[i].c);
        //   scanf("%d %d %d", &student[i].a, &student[i].b, &student[i].c);
    }
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int as = abs(student[i].a - student[j].a);
            int bs = abs(student[i].b - student[j].b);
            int cs = abs(student[i].c - student[j].c);
            int zf = abs(student[i].a + student[i].b + student[i].c - student[j].a - student[j].b - student[j].c);
            if (as < 6 && bs < 6 && cs < 6 && zf < 11)
                sum++;
        }
    }
    printf("%d", sum);
}