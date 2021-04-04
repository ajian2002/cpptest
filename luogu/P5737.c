#include <stdio.h>
int RUNNIAN(int year)
{
    int IF;

    if (year % 100 == 0)
    {
        if (year % 400 == 0)
            IF = 1;
        else
            IF = 0;
        goto cww;
    }
    else if (year % 4 == 0)
        IF = 1;
    else
        IF = 0;
cww:
    return IF;
}
int main()
{
    int begin, end;
    scanf("%d%d", &begin, &end);
    int count = 0;
    int x[end - begin + 1];
    int j = 0;
    for (int i = begin; i <= end; i++)
    {
        if (RUNNIAN(i))
        {
            count++;
            x[j++] = i;
            if ((i + 1) % 100 == 0 || (i + 2) % 100 == 0 || (i + 3) % 100 == 0)
                continue;
            else
                i += 3;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < j; i++)
    {
        printf("%d ", x[i]);
    }
}