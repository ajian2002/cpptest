double jiecheng(int i)
	{
		double sum = 1;
		if (i == 1 || i == 0)
			return 1.0;
		else
		// 	return 1.0 / (1.0 * i * jiecheng(i - 1));
		{
			for (int m = 2; m <= i; m++)
			{
				sum *= 1.0 / (1.0 * m);
			}
			return sum;
		}
	}