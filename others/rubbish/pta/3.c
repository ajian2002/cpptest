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
    FILE *fp  = fopen("stu.dat", "r");
    FILE *fp2 = fopen("stu_sort", "w");
    Source per[21];
    int count = 0;
    for (int i = 0; i < 20; i++)
    {
        fscanf(fp, "%ld,%ld,%ld", &per[i].computer, &per[i].english,
               &per[i].match);
        double sum = (per[i].computer + per[i].english + per[i].match);
        fprintf(fp2, "%ld,%ld,%ld,%ld\n", per[i].computer, per[i].english,
                per[i].match, sum);
    }

    fclose(fp);
    fclose(fp2);
    return 0;
}
