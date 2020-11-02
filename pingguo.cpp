#include <iostream>
using namespace std;
int main()
{
  int n, a, p, s, b, z, max, j, i, sum;
  sum = 0;
  z = 1;
  max = 0;
  //n个苹果5000
  //a椅子 50
  //s 力 1000
  //xi苹果高280
  //b手最长200
  //摘一个费力yi 100
  cin >> n >> s >> a >> b;
  if (n == 0)
  {
    cout << "0";
    return 0;
  }
  int xi[n] = {0};
  int yi[n] = {0};

  for (z = 1; z <= n; z++)
  {
    cin >> xi[z] >> yi[z];
  }

  int temp, bb;
  for (i = 1; i <= n; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (yi[j] < yi[i])
      {
        temp = yi[j];
        bb = xi[j];
        yi[j] = yi[i];
        xi[j] = xi[i];
        yi[i] = temp;
        xi[i] = bb;
      }
    }
  }
  z = 1;
  while (s >= 0 && z <= n)
  {
    if (s >= yi[z] && a + b >= xi[z])
    {
      sum++;
      s -= yi[z];
    }
    z++;
  }
  cout << sum;

  return 0;
}