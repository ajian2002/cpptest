#include <stdio.h>

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {6, 7, 8, 9, 10};
    char buf1 = 'a';
    double buf2 = 2.3;
    int m = -1;
    int n = -2;

    printf("a[4]    = %3d, addr: %p\n", a[4], &a[4]);
    printf("a[0]    = %3d, addr: %p\n", a[0], &a[0]);
    printf("b[4]    = %3d, addr: %p\n", b[4], &b[4]);
    printf("b[0]    = %3d, addr: %p\n", b[0], &b[0]);
    printf("char    = %3c, addr: %p\n", buf1, &buf1);  //为了对齐,空7位,最后一个补1位
    printf("double  = %.1f, addr: %p\n", buf2, &buf2); //与上面地址差8
    printf("m       = %3d, addr: %p\n", m, &m);        //4
    printf("n       = %3d, addr: %p\n", n, &n);
    //4
}