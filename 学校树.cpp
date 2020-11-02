#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int l, m, s;
    s = 0;
    int kai[10000];
    int jie[10000];
    cin >> l;
    cin >> m;
    for (int i = 1; i <= l + 1; i++)
    {
        a[i] = 1;
    }
    for (int s = m; s > 0; s--)
    {
        cin >> kai >> jie;
        for (; kai <= jie; kai++)
        {
            a{kai} = 0;
        }
    }
    for (int j = 1; j <= l + 1; j++)
    {
        if (a[j] == 1)
            sum++;
    }
    cout << sum;

    return 0;
}