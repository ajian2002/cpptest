#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main()
{
    double a, b, c;
    double x, y, z, x1, x2;
    
    int len = 0;
    char o, p, q;
    int max, min;
    char s[100] = {0};
    // scanf("%s", s);
    scanf("%lf%lf%lf", &a, &b, &c);
    double dert = b * b - 4 * a * c;
    if (a == 0 && b == 0 && c)
    {
        printf("Not An Equation");
        return 0;
    }
    if (a == 0 && b == 0 && c == 0)
    {
        printf("Zero Equation");
        return 0;
    }
    if (a)
    {
        if (dert > 0)
        {
            len = 2;
            x1 = ((-1.0 * b) + sqrt(dert)) / (2.0 * a);
            x2 = ((-1.0 * b) - sqrt(dert)) / (2.0 * a);
            printf("%.2lf\n%.2lf", x1,x2);
            return 0;
        }
        else if (dert == 0)
        {
            len = 1;
            x1 = (-1.0 * b) / (2.0 * a);
            printf("%.2lf",x1);return 0;
        }
        else //复数
        {
            
                x1 = (-b) / (2 * a);
                x2 = sqrt(fabs(dert)) / (2 * a);
                printf("%.2lf+%.2lfi\n%.2lf-%.2lfi", x1, x2, x1, x2);return 0;
            
    }}
    else //a==0
    {
        if (b)
        {
            len = 1;
            x1 = (-1.0) * c / (1.0 * b);
            printf("%.2lf", x1);
            return 0;
        }
    }
}
/*2
int s = 2;
void function()
{
    static int m = 0;// quan
    int n = 0;
    if (s)
    {
        m++;
        n++;
        printf("%d %d\n", m, n);
        s--;
        function();
    }
}
8
int add(int *x, int y)
{
    return *x = (*x ^ y);
}
int a;*/
//     /*1
//     unsigned char a = 255;
//     char b = 128; //128>127
//     a -= b;
//     printf("%x,%d\n", b, a);
//     */
//     //2 function();
//     /*3          AAA
//     int A = 65;
//     unsigned int f = 33554433;
//     *(int *)&f >>= 24;
//     *(int *)&f = *(int *)&f + '?'; //63

//     printf("%c", A);
//     */
//     /*4
//     int a[2][2];
//     printf("%p\n%p\n%p\n%p\n", &a[0][0], &a[0][1], &a[1][0], &a[1][1]);
//     printf("%p,%p,%p\n", &a + 1, &a[0] + 1, &a[0][0] + 1);// next      10    01
//     */
//     /* 8
//     int b = 2020;
//     if (add(&b, 1)) //2020   0
//     {
//         printf("XiyouLinuxGroup%d\n", b);
//         printf("Waiting for y%du!\n", a);
//     }
//     /* if (add(&b, 1) && a++)
//     {
//         printf("XiyouLinuxGroup%d\n", b);
//         printf("Waiting for y%du!\n", a);
//     }*/
//     /*9
//     int a = 1;
//     unsigned int c = &a;
//     scanf("%d", (int *)c);
//     printf("%d", a);
// */
//     // char *s[] = {0x6F796958, 0x6E694C75, 0x72477875, 0x3270756F, 0x00313230, 0x00000A};
//     //puts(s);
//     char str[12];
//     fgets(str, 12, stdin);
//     //puts(str);
//     //   printf("%d", sizeof(str));
