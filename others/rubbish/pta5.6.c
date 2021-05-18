#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void menu(void)
{
	printf("1-Ball\n");
	printf("2-Cylinder\n");
	printf("3-Cone\n");
	printf("other-Exit\n");
	printf("Please enter your command:\n");
	return;
}
int main()
{
	int m;
	double r, v, h;
	r = h = v = 0;
	while (1)
	{
		menu();

		v = 0;
		scanf("%d", &m);
		switch (m)
		{
		case 1:
			printf("Please enter the radius:\n");
			scanf("%lf", &r);
			//printf("%d %l \n", m, r);
			v = 4 * 3.14159265 * r * r * r / 3.0;
			printf("%.2lf\n", v);
			break;
		case 2:
			printf("Please enter the radius and the height:\n");
			scanf("%lf %lf", &r, &h);
			v = 3.14159265 * r * r * h;
			printf("%.2lf\n", v);
			break;
		case 3:
			printf("Please enter the radius and the height:\n");
			scanf("%lf %lf", &r, &h);
			v = 3.14159265 * r * r * h / 3.0;
			printf("%.2lf\n", v);
			break;
		default:
			return 0;
		}
	}
	return 0;
}