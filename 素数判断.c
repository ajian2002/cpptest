//**1为素数,0非素数**
//```
#include <math.h>
int sushu(int sss)
{
    int i;
    int part = sqrt(sss);
    // printf("%d", part);
    if (sss == 1 || sss == 0)
    {
        return 0;
    }
    else
    {
        for (i = 2; i <= part; i++)
        {
            if (sss % i == 0)
                return 0;
        }

        return 1;
    }
}
//```