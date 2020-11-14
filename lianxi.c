#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 1000
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    srand((unsigned int)time(NULL));
    int a[NUM];
    int l = -1;
    int r = 143;
    int ma, mi;
    int max = 0, min = 10000;
    // int c = rand() % (r + 1 - l) + l;
    for (int i = 0; i < NUM; i++)
    {
        a[i] = rand() % (r - l) + l;
        //for (int i = 0; i<NUM;i++)
        //printf("%d ", a[i]);
        if (a[i] > max)
        {
            max = a[i];
            ma = i;
        }
        if (a[i] < min)
        {
            min = a[i];
            mi = i;
        }
    }
}