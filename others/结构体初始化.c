#include <stdio.h>
#include <string.h>
struct B
{
    int al;
    char c[12];
    int a;
};
struct A
{
    struct B B1;
    char s[2];
} int main()
{
    struct B b =
        {
            .al = 1,
            //  .a[0] = {311},
            .c = "ssas\0sssasa",
            .a = 1};
    struct A a =
    {
        .B1.al = 3,
        .s = "ss"
    }

    //  strcpy(b.c, "asdsss");
    /// `char *p = B.c;
    //  printf("%s", b.c);
}
