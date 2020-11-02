#include <iostream>
using namespace std;
int main()
{
	int in, ge, shi, bai, qian, wan, shiwan, baiwan, qianwan, out, nian, yeu, ri, f = 0;
	cin >> in >> out;
	for (; in <= out; in++)
	{
		nian = in / 10000;
		yeu = (in - 10000 * nian) / 100;
		ri = in - 10000 * nian - 100 * yeu;

		if (0 >= yeu || yeu > 12 || 0 >= ri || ri > 31) //�ж��·����Ӻϸ�
			continue;
		if ((yeu == 1 || yeu == 3 || yeu == 5 || yeu == 7 || yeu == 8 || yeu == 12 || yeu == 10) && ri > 31)
			continue;
		if ((yeu == 4 || yeu == 6 || yeu == 9 || yeu == 11) && ri > 30)
			continue;
		if ((nian % 4 == 0 && nian % 100 != 0) || nian % 400 == 0) //����
		{
			if (yeu == 2 && ri > 29)
				continue;
		}
		else //ƽ��
		{
			if (yeu == 2 && ri > 28)
				continue;
		}

		ge = in % 10;
		shi = (in % 100 - ge) / 10;
		bai = (in % 1000 - 10 * shi - ge) / 100;
		qian = (in % 10000 - 100 * bai - 10 * shi - ge) / 1000;

		if ((ge * 1000 + 100 * shi + 10 * bai + qian) == nian)
			f++;
	}

	cout << f;
	return 0;
}