#include <stdio.h>
//#include <string.h>
#include <stdlib.h>
#include <cstddef>
#include "getline.c"
int main(int argc, char *argv[])
{
    FILE *read = NULL;
    size_t i = 5;
    char *stream = NULL;
    int xx;
    //printf("%p\n", stream);
    read = fopen("cin.txt", "r");
    //  printf("int xx %p, char *stream指针地址 %p,size_t i%p\n", &xx, &stream, &i);
    printf("stream to %p \n", stream);
    if (read == NULL)
    {
        free(stream);
        fclose(read);
        exit(EXIT_FAILURE);
    }
    //NULL->1 回车->1
    char *temp = stream;
    size_t c = getline1(&stream, &i, read); //goto，长度，from
    printf("%d\n", c);
    printf("%p\n", temp);
    if (temp != (char *)stream)
        printf("空间不够 remalloc\n");
    else
        printf("足够不改变\n");

    //7
    //printf("%s", stream);
    //printf("%p\n", stream);
    //   int len = strlen(stream);
    // printf("%d", len);
    free(stream);
    fclose(read);
    exit(EXIT_FAILURE);
}