#include <stdio.h>
typedef struct
{
    char name[20];
    int chinese;
    int math;
    int english;
    int sum;
} node;
int main()
{

    int n;
    scanf("%d", &n);
    node student[n];
    int max = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d%d%d", student[i].name, &student[i].chinese, &student[i].math, &student[i].english);

        student[i].sum = student[i].chinese + student[i].math + student[i].english;
        if (student[i].sum > max)
        {
            count = i;
            max = student[i].sum;
        }
    }
    printf("%s %d %d %d", student[count].name, student[count].chinese, student[count].math, student[count].english);
}