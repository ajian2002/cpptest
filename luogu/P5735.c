#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double s(double x1, double x2, double y1, double y2)
{
    return pow((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2), 0.5);
}
int main()
{
    double x[3];
    double y[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%lf%lf", &x[i], &y[i]);
    }
    double sum = s(x[0], x[1], y[0], y[1]) + s(x[0], x[2], y[0], y[2]) + s(x[2], x[1], y[2], y[1]);
    printf("%.2f", sum);
}