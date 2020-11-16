#include <stdlib.h>
#include <stdio.h>
#define SIZE 256
/*typedef struct LINKTABLE
{
    int elem_count;
    struct LINKTABLE *NEXT;
} linktable;
*/
struct A
{
    char s[8];
    int xc;
};
struct B
{
    struct A sd;
    char ss;
    int xcc;
};

struct film
{
    char title[SIZE];
    int paper;
    struct film *next;
}

int
main(int argc, char *argv[])
{

    struct film *head = NULL;
    struct film *a, *b;
    char tit[SIZE];
    while (s_gets)
    /* struct A C[2] =
        {
            {"sfdsd", //char [8]
             23},     //int
            {"ssd",
                85}};
    struct B C2[2] =
        {
            {{"sfdsd", 23},
                's',
                234},
            {{"ssd", 85},
                'q',
                44}};
    struct A *de;
    de = &C[0];
    printf("%s", de->s);
    struct B *sfx = &C2[0];
    printf("%d\n", sfx->xcc);

    char chars[2];
    int x, y;
*/
    //sfx->
    //  printf("%p %p %p\n", &x, &chars[0], sfx + 2);
    // printf("%p %p \n", &C[0], &C[1];
    //printf("%p %p", de, de + 1);

    //return 0;
}
char *s_gets(char *st, int n)
{
    char *ret;
    char *find;
    ret = fgets(st, n, stdin);
    if (ret)`
    {
        find = strchar(st, ret);
    }
}