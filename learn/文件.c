#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 0;
    printf("%d\n", n);
    FILE *in = fopen("cin.in", "r+");
    if (in == NULL)
    {
        printf("open file failed");
        return -1;
    }
    char *s = (char *)calloc(20, sizeof(char));
    fgets(s, 6, in);
    printf("%s\n", s);
    fseek(in, 0, SEEK_END);
    printf("%ld\n", ftell(in));

    //fputs(s, in);
}
