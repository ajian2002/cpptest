#include <stdio.h>
double f(double a, double b, double c, double d, double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

int main()
{
    double a, b, c, d;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    for (double i = -100.00; i <= 100.00; i += 0.001)
    {
        if ((f(a, b, c, d, i) * f(a, b, c, d, i + 0.001)) < 0)
        {
            printf("%.2f ", i);
        }
    }
}