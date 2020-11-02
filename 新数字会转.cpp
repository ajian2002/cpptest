#include <iostream>
using namespace std;
int main()
{
  int x, b, m;
  cin >> x;
  b = 0;
  m = x / 10;
  if (x < 0)
  {
    x = -x;
    cout << "-";
  }

  while (x % 10 == 0)
    x /= 10;
  while (x % 10 >= 0)
  {
    b = x % 10;
    x /= 10;
    cout << b;
    if (x < 1)
      return 0;
  }
  if (x == 0)
    cout << 0;
  return 0;
}