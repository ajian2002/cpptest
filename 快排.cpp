#include <stdio.h>
void quickSort(int s[], int l, int r);

int main()
{
	int min, i, len, z, x, c, a[50];
	scanf("%d", &len);
	for (i = 0; i < len; i++)
		scanf("%d", &a[i]);
	quickSort(a, 0, len - 1);

	for (i = 0; i < len; i++)
		printf("%d ", a[i]);
	return 0;
}
void quickSort(int s[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) //
				j--;

						if (i < j)
				s[i++] = s[j];
			while (i < j && s[i] < x) //
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quickSort(s, l, i - 1); //
		quickSort(s, i + 1, r);
	}
}