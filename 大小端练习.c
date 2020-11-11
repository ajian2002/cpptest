#include <stdio.h> //大小端深刻理解
int main()
{
    int x;
    printf("%x\n", &x);
    int a = 0x12345678;
    printf("%x\n", &a);
    int m = 1;
    printf("%x\n", &m);
    int *c[2] = {&a, &m};
    char p = *c[0];
    printf("%x   %x\n", *c, &p);
    char q = *(c[1] + 2);
    printf("%x\n\n", (int)(&x) - 1);
    printf("%x \n%x", p, *(char *)((int)(&x) - 1));

    int z;
    printf("%x\n", &z);
    int b = 0x12345678;
    printf("%x\n", &b);

    int *d[2] = {&b, &z};
    char p1 = *d[0];
    // printf("%x   %x\n", *c, &p);
    char q1 = *((char *)(d[1]) - 1);
    printf("%x\n%x\n", p1, q1);
}
