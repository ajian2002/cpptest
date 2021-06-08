#include <stdio.h>
typedef struct
{
    char name[20];
    char id[20];
    char class[20];
    char adree[20];
} Stu;
int main()
{
    FILE *fp = fopen("stu.dat", "w+");
    Stu per[21];
    for (int i = 0; i < 20; i++)
    {
        scanf("%s%s%s%s", per[i].name, per[i].id, per[i].class, per[i].adree);
        fprintf(fp, "%s %s %s %s\n", per[i].name, per[i].id, per[i].class,
                per[i].adree);
    }
    fclose(fp);
    return 0;
}
