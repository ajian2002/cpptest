#include <stdio.h>
#include <string.h>
long yue(long x, long y)
{
    long r;
    r = x % y;
    if (r != 0)
    {
        x = y;
        y = r;
        yue(x, y);
    }
    else
    {
        return y;
    }
}
int main()
{
    int n;
    char c;
    scanf("%d", &n);
    long song[n];
    long father[n];
    char s[100] = {0};
    long p;
    long sumfather, sumsong;
    sumfather = sumsong = 0;
    long tempfather, tempsong;

    // sscanf(s, "%d/%d", &song[0], &father[0]);
    // printf("%s\n", s);
    // printf("%d %d ", song[0], father[0]);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        sscanf(s, "%ld/%ld", &song[i], &father[i]);
        if (i != 0)
        {
            tempfather = sumfather;
            tempsong = sumsong;
            p = yue(tempfather, father[i]);
            sumfather = father[i] * tempfather / p;
            sumsong = sumfather / tempfather * tempsong + sumfather / father[i] * song[i];
        }
        else
        {
            sumfather = father[0];
            sumsong = song[0];
        }
        // printf("sum :%ld,%ld\n", sumsong, sumfather);
    }
    if (sumsong >= sumfather) //zheng
    {
        printf("%d", sumsong / sumfather);
        sumsong %= sumfather;
        if (sumsong != 0) //fen
        {
            printf(" ");
            tempfather = sumfather;
            tempsong = sumsong;
            p = yue(sumfather, sumsong);
            sumfather /= p;
            sumsong /= p;
            if (sumfather == 1)
            {
                printf("%ld", sumsong);
            }
            else if (sumfather == -1)
            {
                printf("-%ld", sumsong);
            }
            else
            {
                printf("%ld/%ld", sumsong, sumfather);
            }
        }
    }
    else //fen
    {
        if (sumsong == 0)
        {
            printf("0");
            return 0;
        }
        tempfather = sumfather;
        tempsong = sumsong;
        p = yue(sumfather, sumsong);
        sumfather /= p;
        sumsong /= p;
        if (sumfather == 1)
        {
            printf("%ld", sumsong);
        }
        else if (sumfather == -1)
        {
            printf("-%ld", sumsong);
        }
        else
        {
            printf("%ld/%ld", sumsong, sumfather);
        }
    }
}