#include <stdio.h>

enum DAY
{
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};

int main(int argc, char *argv[])
{
    enum DAY day;
    day = MON;
    // scanf("%u", &day);
    printf("%d", day);
    return 0;
}