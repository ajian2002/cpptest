#include <stdio.h>
typedef struct
{
    double computer;
    double english;
    double match;
    double average;
} Source;
int main()
{
    FILE *fp = fopen("stu.dat", "r");
    Source per[21];
    int count = 0;
    for (int i = 0; i < 20; i++)
    {
        fscanf(fp, "%ld,%ld,%ld", &per[i].computer, &per[i].english,
               &per[i].match);
        per[i].average = (per[i].computer + per[i].english + per[i].match) / 3;
        if (per[i].average >= 90) count++;
    }
    printf("%d\n", count);
    fclose(fp);
    return 0;
}
