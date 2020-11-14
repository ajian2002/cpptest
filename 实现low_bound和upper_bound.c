#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 35
#define KEY 4
int low_bound(int *begin, int *end, int key); //查找有序区间中第一个大于或等于某给定值的元素的位置
int upper_bound(int *begin, int *end, int key);
void qsort(int *p, int l, int r);
int main()
{

    int arr[NUM];

    srand((unsigned)time(NULL));
    for (int i = 0; i < NUM; i++)
        arr[i] = rand() % 10;
    // for (int i = 0; i < rand() % 10; i++)
    //arr[i] = KEY;

    // arr[3] = KEY;

    qsort(arr, 0, NUM - 1);
    int s = -1;
    printf("数组 ");
    while (++s != NUM)
        printf("%2d ", arr[s]);
    s = -1;
    printf("\n下标 ");
    while (++s != NUM)
        printf("%2d ", s);

    int l = low_bound(&arr[0], &arr[NUM], KEY);
    int r = upper_bound(&arr[0], &arr[NUM], KEY);
    //printf("%d\n", arr[0]);
    printf("\n%d,%d\n", l, r);
}
int low_bound(int *begin, int *end, int key) //zuo
{
    // printf("%p,%p", begin, end);
    int *bbee = begin;
    int *b = begin;
    int *e = end;
    while (b <= e)
    {
        int len = (e - b);
        // printf(" %d", len);
        int *midd = (b) + (len / 2);
        // printf("   %d   ", *mid);
        //printf("\n%p  ", mid);
        if (key < *midd)
            e = midd - 1;
        else if (key == *midd)
        {

            if (key > *(midd - 1))
                return (midd - bbee);
            else
                e = midd - 1;
        }
        else
            b = midd + 1;
    }
}
int upper_bound(int *begin, int *end, int key) //you
{
    int *bbee = begin;
    int *bb = begin;
    int *ee = end;
    int sum = 0;
    while (bb <= ee)
    {
        int len = (ee - bb);
        // printf(" %d", len);
        int *mid = (bb) + (len / 2);
        //printf("   %d   ", *mid);
        //printf("\n%p  ", mid);
        if (key < *mid)
            ee = mid - 1;
        //return 1;
        else if (key == *mid)
        {
            sum++;
            if (*(mid + sum) > key)
                return (mid + sum - bbee);
            //return (mid - bb - 1);
        }
        else
            bb = mid + 1;

        //return -1;
        //if (sum>0&&)
    }
    // return -1;
    //   w:
}
void qsort(int *p, int l, int r)
{
    int j = l, k = r;
    if (l < r)
    {
        int temp = p[l];
        while (l != r)
        {
            while (l < r && p[r] >= temp)
                r--;
            p[l] = p[r];
            while (l < r && p[l] <= temp)
                l++;
            p[r] = p[l];
        }
        if (r == l)
            p[r] = temp;

        qsort(p, r + 1, k);
        qsort(p, j, r - 1);
    }
}
