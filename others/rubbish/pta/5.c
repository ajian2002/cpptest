#include <stdio.h>
int main()
{
    FILE* fp1 = NULL;
    FILE* fp2 = NULL;
    char a;
    fp1 = fopen("1.txt", "r");
    fp2 = fopen("2.txt", "a+");
    while (!feof(fp1))
    {
        a = fgetc(fp1);
        fputc(a, fp2);
    }
    fclose(fp1);
    fclose(fp2);
}