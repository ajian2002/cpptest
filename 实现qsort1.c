#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *getdata(void *a)
{ //待更改
    //printf("%d\n", *(int *)a);
    return (int *)a;
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
    // int *j=getdata( p;
    //void *k = p + (count - 1) * size;
    if (count > 1)
    {
        //getdata(p);
        //void *jj = *(char *)p + size;
        int jj = 0;

        for (int i = 0; i <= size * count; i += size)
            if (compare(p, p + i) > 1)
            {
                swapany(p + i, p + jj, size);
                jj += size;
            }

        //swapany(p, p + jj, size);

        // for (int i = 0; i < count * size; i += size)
        //   printf("%d ", getdata(p + i));

        /*  for (int i = 0; i <= count * size; i += size)
            printf(" %d ", getdata((char *)p + i));
        printf("\n");
*/
        qsort(p + jj, count - jj / size, size, compare);
        qsort(p, jj / size, size, compare);
    }
}

int main()
{
    //srand((unsigned int)time(NULL));
    //int a[NUM] = {0};
    /*
    int i = 0, n = 0;
    //printf("输入数目个数");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
*/
    //int l = 0;
    //int r = n - 1;
    int n = 10;
    int a[n];
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
        a[i] = rand() % 10;
    for (int i = 0; i < n; i++)
        printf(" %d ", a[i]);
    printf("\n");
    qsort(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]), compare);
    for (int i = 0; i < n; i++)
        printf(" %d ", a[i]);
    //getchar();
}
