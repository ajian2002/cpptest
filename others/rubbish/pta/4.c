#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    double computer;
    double english;
    double match;
    double average;
} Source;
int compare(const void *a, const void *b)
{
    Source *x = a;
    Source *y = b;
    return y->average - x->average;  //大到小
}
int main()
{
    Source temp;
    scanf("%ld,%ld,%ld", &per[20].computer, &per[20].english, &per[20].match);
    per[20].average = (per[20].computer + per[20].english + per[20].match) / 3;

    FILE *fp  = fopen("stu.dat", "r");
    FILE *fp2 = fopen("stu_new", "w");
    Source per[22];
    int count = 0;
    for (int i = 0; i < 20; i++)
    {
        fscanf(fp, "%ld,%ld,%ld", &per[i].computer, &per[i].english,
               &per[i].match);
        per[i].average = (per[i].computer + per[i].english + per[i].match) / 3;
    }
    qsort(per, sizeof(Source), 21, compare);
    for (int i = 0; i < 21; i++)
    {
        fprintf(fp2, "%ld,%ld,%ld", per[i].computer, per[i].english,
                per[i].match);
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}
