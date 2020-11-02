#include <iostream>
using namespace std;
int main()
{
  int n, a, m, x, sum;
  int c[20];
  sum = 0;
  cin >> a >> n >> m >> x;
  sum = a;
  c[1] = a;
  c[0] = 0;
  for (int i = 2; i <= n - 1; i++)
  {
    c[i] = c[i - 1] + c[i - 2];

    sum += c[i] - c[i - 2];
    if (x == i)
    {
      cout << sum;
    }
  }
  return 0;
}