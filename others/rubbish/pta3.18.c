#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int compare(char *a, char *b)
{
    return (*a > *b);
}
int main()
{
    int n, m;
    int count = 0;
    char buf[10000];
    memset(buf, 0, sizeof(char) * 10000);
    // scanf("%s", buf);
    // getline(buf, 10000, stdin);
    fgets(buf, 10000, stdin);
    buf[strlen(buf) - 1] = 0;
    qsort(buf, strlen(buf), sizeof(char), compare);
    int len = strlen(buf);
    char *temp = &buf[0];
    printf("begin:%s\n", buf);
    for (int i = 1; i < strlen(buf); i++)
    {
        if (strncmp(&buf[i], temp, 1) == 0)
        {
            int s = strlen(buf);
            memmove(temp, &buf[i], strlen(buf) - i);
            buf[s - 1] = 0;
            i--;
            printf("%s\n", buf);
        }
        else
        {
            temp = &buf[i];
        }
    }
    printf("final:%s", buf);
}