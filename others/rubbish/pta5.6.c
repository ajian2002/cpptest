int mons[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int year, mon, day;
int Isyear(int year)  //判断是否闰年
{
    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
        return 1;
    else
        return 0;
}
struct DateG days2Date(int x)
{
    struct DateG t = {1, 1, 1};
    for (int i = 0; i < x; i++)
    {
        if (Isyear(t.yy))
        {
            mons[1] = 29;
        }
        else
        {
            mons[1] = 28;
        }
        t.dd++;
        if (t.dd > mons[t.mm - 1])
        {
            t.mm++;
            t.dd = 1;
            if (t.mm > 12)
            {
                t.yy++;
                t.mm = 1;
            }
        }
    }
    return t;
}
int Days(struct DateG x)  // {2,,4,11}    return 465   from{1,1,1}
{
    int year = x.yy, mon = x.mm, day = x.dd;
    int sum = 0;                    //从1年1月1日到今天的总天数
    for (int i = 1; i < year; i++)  //计算从开始到去年的年份天数之和
    {
        if (Isyear(i))  //闰年加366
            sum += 366;
        else  //不是闰年加365
            sum += 365;
    }
    if (Isyear(year))
    {
        mons[1] = 29;
    }
    else
    {
        mons[1] = 28;
    }
    for (int i = 0; i < mon - 1; i++)  //加到今年的前一个月的天数和
        sum += mons[i];
    sum += day;  //加这个月的天数
    return sum - 1;
}
