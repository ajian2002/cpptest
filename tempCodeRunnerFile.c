#include <stdio.h>
#include <stdlib.h>
#define NUM 5
#define KEY 4
int low_bound(int *begin, int *end, int key); //查找有序区间中第一个大于或等于某给定值的元素的位置
int upper_bound(int *begin, int *end, int key);

void qsort(int *p, int l, int r);
int main()
{
    int arr[NUM] = {rand()};
    //int arr[NUM] = {5, 4, 3, 2, 1};
    arr[rand() % NUM + 1] = KEY;
    //arr[3] = KEY;
    qsort(arr, 0, NUM - 1);
    //printf("%d,%d", arr[3], arr[1]);
    //int key=KEY;
    int l = low_bound(&arr[0], &arr[NUM], KEY);
    int r = upper_bound(&arr[0], &arr[NUM], KEY);
    printf("\n%d,%d\n", l, r);
    //return 0;
}
int low_bound(int *begin, int *end, int key) //zuo
{
    printf("%d,%d", begin, end);
    int mid = (end - begin)/sizeof(int*);
    return mid;
}
int upper_bound(int *begin, int *end, int key) //you
{
    return -1;
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
