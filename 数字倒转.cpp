#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	long int i, a, s, d, f, g, h, j, k, t, l, o;
	i = 0;
	cin >> i;
	a = s = d = f = g = h = j = k = l = o = t = 0;
	a = i % 10;

	s = i / 10 % 10;

	d = i / 100 % 10;

	f = i / 1000 % 10;

	g = i / 10000 % 10;

	h = i / 100000 % 10;

	j = i / 1000000 % 10;

	k = i / 10000000 % 10;

	l = i / 100000000 % 10;

	o = i / 1000000000 % 10;

	if (a != 0)
		kaishi = a;
	else
	{
		if (s != 0)
			kaishi = s;
		else
		{
			if (d != 0)
				kaishi = d;
			else
			{
				if (f != 0)
					kaishi = f;
				else
				{
					if (g != 0)
						kaishi = g;
					else
					{
						if (h != 0)
							kaishi = h;
						else
						{
							if (j != 0)
								kaishi = i;
							else
							{
								if (k != 0)
									kaishi = j;
								else
								{
									if (l != 0)
										kaishi = k;
									else
									{
										if (o != 0)
											kaishi = l;
										else
										{
											cout << 0;
											return 0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (o == 0)
	{
		if (l == 0)
		{
			if (k == 0)
			{
				if (j == 0)
				{
					if (h == 0)
					{
						if (g == 0)
						{
							if (f == 0)
							{
								if (d == 0)
								{
									if (s == 0)
									{
										if (a == 0)
										{
											cout << 0;
											return 0;
										}
										else
											jieshu = l;
									}
									else
										jieshu = k;
								}
								else
									jieshu = j;
							}
							else
								jieshu = h;
						}
						else
							jieshu = g;
					}
					else
						jieshu = f;
				}
				else
					jieshu = d;
			}
			else
				jieshu = s;
		}
		else
			jieshu = a;
	}
	if (kaishi == a || jieshu == a)
		cout << a;
	if (kaishi == a && jieshu == s)
		cout << a << s;
	if (kaishi == a && jieshu == d)
		cout << a << s << d;
	if (kaishi == a && jieshu == f)
		cout << a << s << d << f;
	  if (kaishi==a&&jieshu==
       
       
	  						 
	    
	
	     	
	     
	  
        return 0;
}
