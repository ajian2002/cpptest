#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*extern int a;
void arr()
{
    printf("test2 %d\n", a);
}*/
int main()
{
    char *size = (char *)malloc(100);
    //printf("%d\n", size[0]);
    //scanf("%s", size);
    // int len = strlen(size);
    for (int i = 0; i < 100; i++)
        printf("%d \n", size[i]);

    free(size);
    //EXIT_FAILURE     1
    //EXIT_SUCCESS     0
}