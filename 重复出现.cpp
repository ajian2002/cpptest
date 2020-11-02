#include <iostream>
using namespace std;
int main()
{
	int a, s, d, f, z, g, h, j, x, n;
	z = 0;

	a = s = d = f = g = h = j = 75;
	cin >> n >> x;
	for (int i = n; i <= x; i++)
	{
		a = i % 10;
		if (i > 9)
			s = i / 10 % 10;
		if (i > 99)
			d = i / 100 % 10;
		if (i > 999)
			f = i / 1000 % 10;
		if (i > 9999)
			g = i / 10000 % 10;
		if (i > 99999)
			h = i / 100000 % 10;

		if (a == x)
			z++;
		if (s == x)
			z++;
		if (d == x)
			z++;
		if (f == x)
			z++;
		if (g == x)
			z++;
		if (h == x)
			z++;
	}
	cout << z;
	return 0;
}