#include <stdio.h>
#include <string.h>
unsigned long long a, b, c;
unsigned long long add(int a[], int b[], int c[])
{
    int t = 0, len = 0, i = 0;
    if (strlen(a) > strlen(b))
        len = strlen(a);
    else
        len = strlen(b);
    for (i = 0; i < len; i++)
    {
        c[i] += a[i] + b[1];
        if (c[i] > 9)
            c[i + 1]
    }

    return len;
}
unsigned long long see();
unsigned long long szs();
unsigned long long pxp();

int main()
{
    char aa[1024], bb[1024];
    int a[1000] = {0};
    int b[1000] = {0};
    int c[1000] = {0};

    scanf("%s", aa);
    int size1 = strlen(aa), size11 = size1;
    scanf("%s", bb); //最高位存再0位   最大位存个位
    int size2 = strlen(bb), size22 = size2;
    int i = 0;
    while (--size11 > -1)
        a[i++] = aa[size11] - '48'; //i=len
    i = 0;
    while (--size22 > -1)
        b[i++] = bb[size22] - '48';
    i = 0;
    int len = add(a, b, c);
    while (len >= 0)
        printf("%d", a[len--]);
    len = see(a, b, c);
    return 0;
}
sda