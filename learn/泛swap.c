#define MYERROR
#include <my/debug.info.h>
void aswap(void *a, void *b, int size)
{
    char temp;
    char *t, *p;
    t = (char *)a;
    p = (char *)b;
    for (int i = 0; i < size; i++, t++, p++)
    {
        temp = *t;
        *t = *p;
        *p = temp;
    }
}
int main()
{
    int a, b;
    a = 0;
    b = 1;
    double c, d;
    c = 1.0, d = 2.0;
    aswap(&a, &b, sizeof(int));
    printf("%d %d\n", a, b);
    aswap(&c, &d, sizeof(double));
    printf("%f %f", c, d);
    PRINTEXIT("error");
    return 0;
}