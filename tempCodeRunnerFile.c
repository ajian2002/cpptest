
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tag_unimportant
{
    char *t2;
    int t1;
} A;
//int df = 0x20200011;
void func(A *a)
{
    a = (A *)malloc(sizeof(A));
    a->t1 = 0x20200011; //指针指向常量
    a->t2 = (char *)(a->t1);

    //    printf("%x", *(a->t2));
    *(a->t2) = 0x00;
    //0x20200000(int)
    strcpy(a->t2, "xiyoulinux");
}
int main(int argc, char *argv[])
{
    A *a;
    func(a);
    printf("%x\n", a->t1); //  //0x20200000(int)
    printf("%s\n", a->t2); //  xiyoulinux
    return 0;
}