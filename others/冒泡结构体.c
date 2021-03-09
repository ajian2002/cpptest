#include <stdio.h>
int a[50];
void MAOPAO(int len, int a[50])
{
    int x, z, min;
    x = 1;
    z = 1;
    for (x = 1; x < len; x++)
        for (z = 1; z < len; z++)
            if (a[z - 1] > a[z])
            {
                min = a[z];
                a[z] = a[z - 1];
                a[z - 1] = min;
            }
}
int main()
{
    int min, i, len, z, x, c, a[50];
    //scanf("%d", &len);
    len = 3;
    for (i = 0; i < len; i++)
        scanf("%d", &a[i]);

    MAOPAO(len, a[len]);
    /*
    for (x = 1; x < len; x++)
        for (z = 1; z < len; z++)
            if (a[z - 1] > a[z])
            {
                min = a[z];
                a[z] = a[z - 1];
                a[z - 1] = min;
            }
*/
    /*for (x = 1; x < len; x++)
		for (z = 1; z < len; z++)
			if (a[z - 1] < a[z])
			{
				min = a[z - 1];
				a[z - 1] = a[z]; 
				a[z] = min;
			}
*/
    for (i = 0; i < len; i++)
        printf("%d ", a[i]);

    return 0;
}
