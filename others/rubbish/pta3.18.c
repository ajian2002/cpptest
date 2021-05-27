#include <stdio.h>

char leapYear(int year)  //闰年否
{
    char IF;

    if (year % 100 == 0)
    {
        if (year % 400 == 0)
            IF = '1';
        else
            IF = '0';
        goto cww;
    }
    else if (year % 4 == 0)
        IF = '1';
    else
        IF = '0';
cww:
    return IF;
}
struct DateG
{
    int yy, mm, dd;
};
struct DateG days2Date(int x)
{
    // from:{1,1,1} + 100-->{1,4,11}
    struct DateG mm = {1, 1, 1};
    int temp        = x;
    while (1)
    {  // 31+28+31+10==100+1
        if ('1' == leapYear(mm.yy) && temp >= 366)
        {
            mm.yy += 1;
            temp -= 366;
        }
        else if ('0' == leapYear(mm.yy) && temp >= 365)
        {
            mm.yy += 1;
            temp -= 365;
        }
        else
        {
            break;
        }
    }
    int i = mm.mm;
    while (1)
    {  // 31+28+31+10==100+1

        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 ||
            i == 12)
        {
            if (temp >= 31)
            {
                i += 1;
                if (i == 13)
                {
                    i = 1;
                    mm.yy += 1;
                }
                temp -= 31;
            }
            else
            {
                mm.mm = i;
                break;
            }
        }
        else if (i == 2)
        {
            if ('1' == leapYear(mm.yy))
            {
                if (temp >= 29)
                {
                    i += 1;
                    temp -= 29;
                }
                else
                {
                    mm.mm = i;
                    break;
                }
            }
            else
            {
                if (temp >= 28)
                {
                    i += 1;
                    temp -= 28;
                }
                else
                {
                    mm.mm = i;
                    break;
                }
            }
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11)
        {
            if (temp >= 30)
            {
                i += 1;
                temp -= 30;
            }
            else
            {
                mm.mm = i;
                break;
            }
        }
        else
        {
            mm.mm = i;
            break;
        }
    }

    mm.dd += temp;
    if (mm.mm == 2)
    {
        if ('1' == leapYear(mm.yy))
        {
            if (mm.dd > 29)
            {
                mm.dd %= 29;
                mm.mm += 1;
            }
        }
        else
        {
            if (mm.dd > 28)
            {
                mm.dd %= 28;
                mm.mm += 1;
            }
        }
    }
    else if (mm.mm == 4 || mm.mm == 6 || mm.mm == 9 || mm.mm == 11)
    {
        if (mm.dd > 30)
        {
            mm.dd %= 30;
            mm.mm += 1;
        }
    }
    else
    {
        if (mm.dd > 31)
        {
            mm.dd %= 31;
            mm.mm += 1;
        }
    }

    return mm;
}
int Days(struct DateG x)
{
    int sum = 0;
    for (int i = 1; i < x.yy; i++)
    {
        if ('1' == leapYear(i))
        {
            sum += 366;
        }
        else
        {
            sum += 365;
        }
    }
    for (int i = 1; i < x.mm; i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 ||
            i == 12)
        {
            sum += 31;
        }
        else if (i == 2)
        {
            if ('1' == leapYear(x.yy))
            {
                sum += 29;
            }
            else
            {
                sum += 28;
            }
        }
        else
        {
            sum += 30;
        }
    }
    return sum + x.dd - 1;

}  // {2,,4,11}    return 465   from{1,1,1}

int main()
{
    struct DateG mm = {2001, 1, 1};
    struct DateG nn = {1919, 9, 9};
    struct DateG xx = days2Date(60 * 365 + Days(mm));
    printf("%d.%d.%d\n", xx.yy, xx.mm, xx.dd);
    nn = days2Date(Days(xx) - 1000);
    printf("%d.%d.%d\n", nn.yy, nn.mm, nn.dd);
    struct DateG zz = {2020, 1, 23};
    printf("%.2f\n", (Days(zz) - Days(mm)) / 365.0);
}
