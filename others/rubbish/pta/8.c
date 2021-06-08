#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 4096
int main()
{
    FILE *file1, *file2;
    file1             = fopen("1.txt", "r");
    file2             = fopen("2.txt", "r");
    char s1[BUF_SIZE] = {0};
    char s2[BUF_SIZE] = {0};
    fread(s1, sizeof(char), BUF_SIZE, file1);
    fread(s2, sizeof(char), BUF_SIZE, file2);
    fclose(file1);
    fclose(file2);
    char *ptr1, *ptr2;
    ptr1 = s1;
    ptr2 = s2;
    while (*ptr1 == *ptr2)
    {
        ptr1++;
        ptr2++;
    }
    if (*ptr1 == *ptr2 && *ptr1 == 0)
        return 0;
    else
        return *ptr1 - *ptr2;
}