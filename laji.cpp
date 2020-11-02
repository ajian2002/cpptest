#include <iostream>
using namespace std;
int main()
{
	int in, ge, shi, bai, qian, wan, shiwan, baiwan, qianwan, out, nian, yeu, ri, f = 0;
	cin >> in >> out;
	for (; in <= out; in++)
	{
		ge = in % 10;
		shi = in % 100 - ge;
		bai = in % 1000 - 10 * bai - ge;
		qian = in % 10000 - 100 * bai - 10 * shi - ge;
		wan = in % 100000 - 1000 * qian - 100 * bai - 10 * shi - ge;
		shiwan = in % 1000000 - 100000 * wan - 1000 * qian - 100 * bai - 10 * shi - ge;
		baiwan = in % 10000000 - 1000000 * shiwan - 100000 * wan - 1000 * qian - 100 * bai - 10 * shi - ge;
		qianwan = in % 100000000 - 10000000 * baiwan - 1000000 * shiwan - 100000 * wan - 1000 * qian - 100 * bai - 10 * shi - ge;
		yeu = 10 * qian + bai;
		nian = 1000 * qianwan + 100 * baiwan + 10 * shiwan + wan;
		ri = 10 * shi + ge;
		if (0 > yeu && yeu < 12 && 0 > ri && ri > 31) //�ж��·����Ӻϸ�
			continue;
		if (yeu == 1 && yeu == 3 && yeu == 5 && yeu == 7 && yeu == 8 && yeu == 12 && yeu == 10 & ri > 31)
			continue;
		if (yeu == 4 && yeu == 6 && yeu == 9 && yeu == 11 && ri > 30)
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

		if (ge == qianwan && shi == baiwan && bai == shiwan && qian == wan)
			f += 1;
	}

	cout << f;
	return 0;
}
