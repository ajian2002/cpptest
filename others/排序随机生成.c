#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int getdata(void *a) //待更改
{
    return *(int *)a;
}
int compare(const void *a, const void *b) //待优化
{
    return (*(int *)a > *(int *)b);
}
void swapany(void *a, void *b, int size) //交换任意类型的数据
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        char temp = *((char *)a + i);
        *((char *)a + i) = *((char *)b + i);
        *((char *)b + i) = temp;
    }
}
void qsort(void *p, int count, int size, int (*compare)(const void *, const void *))
{
    // srand((unsigned int)time(NULL));
    /* 伪快排(像是冒泡)
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (compare((char *)p + j * size, (char *)p + (j + 1) * size))
            {
                swapany((char *)p + j * size, (char *)p + (j + 1) * size, size);
                //jj++;
            }
        }
    }
    */
    //摸索
    void *j = p;
    void *k = p + (count - 1) * size;
    if (count > 1)
    {
        //getdata(p);
        //void *jj = *(char *)p + size;
        int jj = 0;
        for (int i = 0; i <= size * count; i += size)
            if (getdata(p + i) < getdata(p))
            {
                swapany(p + i, p + jj, size);
                jj += size;
            }

        swapany(p, p + jj, size);
        //qsort(p, jj, k);
        //qsort(p, j, jj - 1);
    }
}
int main()
{

    // int n;
    //scanf("%d", &n);
    int n = 15;
    int a[n];
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
        a[i] = rand() % 10;

    qsort(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]), compare);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}