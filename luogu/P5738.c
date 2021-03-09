#include <stdio.h>
double jisuan(int ci[], int m)
{
    int max = -1;
    int min = 10000;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += ci[i];
        if (ci[i] > max)
            max = ci[i];
        if (ci[i] < min)
            min = ci[i];
    }
    sum -= max + min;
    return sum * 1.00 / (m - 2);
}
int main(int argc, char argv[])
{
    int n, m;
    scanf("%d%d", &n, &m);
    double fen;
    int ci[m];
    double max = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &ci[j]);
        }
        fen = jisuan(ci, m);
        if (fen > max)
        {
            max = fen;
        }
    }
    printf("%.2f", max);
}