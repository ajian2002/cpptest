#include <stdio.h>
#define size 10;
double x(int a, int b, int c, int d, int s);
int s1(int a, int b, int c, int d, int s);
int main()
{
    int a, b, c, d, s;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    s = -100;
    double xx1 = x(a, b, c, d, s);
    if (xx1 > (int)(xx1))
        s = (int)(xx1) + 2;
    else
        s = (int)(xx1) + 1;
    // s = (int)(xx1) + 1;
    double xx2 = x(a, b, c, d, s);
    if (xx2 > (int)(xx2))
        s = (int)(xx2) + 2;
    else
        s = (int)(xx2) + 1;
    //s = (int)(xx2) + 1;
    double xx3 = x(a, b, c, d, s);
    printf("%.2f %.2f %.2f ", xx1, xx2, xx3);
}
int ss1(int a, int b, int c, int d, int s)
{
    int s1 = (a * s * s * s + b * s * s + c * s + d);
    int s2 = (a * (s + size) * (s + size) * (s + size) + b * (s + size) * (s + size) + c * (s + size) + d);
    int s3 = (a * (s - size) * (s - size) * (s - size) + b * (s - size) * (s - size) + c * (s - size) + d);
    if (s1 * s2 < 0)
        return s;
    else
        s += size;
    ss1(a, b, c, d, s);
    //   return s1;
}
double x(int a, int b, int c, int d, int s)
{

    double sum = s * 1.000;
    while ((a * sum * sum * sum + b * sum * sum + c * sum + d) * (a * (sum + 1) * (sum + 1) * (sum + 1) + b * (sum + 1) * (sum + 1) + c * (sum + 1) + d) > 0)
        sum += 1;
    while ((a * sum * sum * sum + b * sum * sum + c * sum + d) * (a * (sum + 0.1) * (sum + 0.1) * (sum + 0.1) + b * (sum + 0.1) * (sum + 0.1) + c * (sum + 0.1) + d) > 0)
        sum += 0.1;
    while ((a * sum * sum * sum + b * sum * sum + c * sum + d) * (a * (sum + 0.01) * (sum + 0.01) * (sum + 0.01) + b * (sum + 0.01) * (sum + 0.01) + c * (sum + 0.01) + d) > 0)
        sum += 0.01;
    while ((a * sum * sum * sum + b * sum * sum + c * sum + d) * (a * (sum + 0.001) * (sum + 0.001) * (sum + 0.001) + b * (sum + 0.001) * (sum + 0.001) + c * (sum + 0.001) + d) > 0)
        sum += 0.001;
    if (((int)(sum * 1000)) % 10 > 4)
        sum = ((int)(sum * 100)) / 100.00 + 0.01;
    else
        sum = ((int)(sum * 100)) / 100.00;
    return sum;
}
