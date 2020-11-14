#include <stdlib.h>
#include <stdio.h>
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

int main(int argc, char *argv[])
{
    struct A C[2] =
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
    char chars[2];
    int x, y;
    int *sfx = &x;

    printf("%p %p %p\n", &x, &chars[0], sfx + 2);
    printf("%p %p \n", &C[0], &C[1];
    printf("%p %p", de, de + 1);

    //return 0;
}