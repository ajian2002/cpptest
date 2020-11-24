#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *read = NULL;
    char *stream = NULL;
    size_t i = 0;
    read = fopen("cin.txt", "r");
    //空回车占2
    
    int c = getline(&stream, &i, read); //goto，长度，from
    printf("%d\n", c);
    printf("%s\n", stream);
    free(stream);
    fclose(read);
}