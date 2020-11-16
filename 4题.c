#include <stdio.h>
#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)
int main(int argc, char **argv)
{
    int a = 2147483645;

    char f = 0x1FULL;

    printf("%p\n", f);
    return 0;
}