#include <stdio.h>
int getci(int n)
{
    int sum = 0;
    int i;
    for (i = 0; i <= n; i++)
    {
        sum += i;
        if (sum + i + 1 >= n && sum < n)
            break;
    }
    i = i + 1; //i列
    sum += 1;  //开始项
               // sum2 = i + 1; // sum2和
    if (i % 2)
    {
        int x = i;
        int y = 1;
        for (int j = 0; j < n - sum; j++)
        {
            x--;
            y++;
        }
        printf("%d/%d", x, y);
        return 0;
    }
    else
    {

        int x = 1;
        int y = i;
        for (int j = 0; j < n - sum; j++)
        {
            x++;
            y--;
        }
        printf("%d/%d", x, y);
        return 0;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int p = getci(n);
    //r  printf("%d", p);
}