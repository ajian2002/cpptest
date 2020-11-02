#include <stdio.h>
void ccc(int j, int l, int tt)
{

    int sum;

    sum = j + l;
    printf("%d ", sum);
    l = j;
    j = sum;
    tt--;
    if (tt > 0)
    {
        ccc(j, l, tt);
        /* code */
    }
    else
    {
        return 0;
    }
}
int main()
{
    int a, b, temp, c, d;
    a = 1;
    b = 1;
    temp = 10;
    printf("%d %d ", a, b);
    ccc(a, b, temp);

    return 0;
}