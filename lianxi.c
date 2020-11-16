#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    /*
    char aa[size];
    char bb[size];
    void *c = aa;
    memcpy(aa, b, size);
    b = memcpy(b, a, size);
    a = memcpy(a, aa, size);
*/}
    void qsort(void *p, size_t count, size_t size, int (*compare)(const void *a, const void *b))
    {

        printf("%p %p\n", p, (char *)p + size);
        swapany(p, (char *)p + size, size);
        printf("%d %d\n", *(int *)p, *(int *)((char *)p + size));
    }
    //#define NUM 1000

    /*
void sq(void *p, size_t n, size_t s)
{
    int j = *p;
    int k = *(p + n);
    printf("%p,%p", j, k);
}*/
    int main()
    {
        // qsort();
        int len = 10;
        // srand((unsigned int)time(NULL));
        int a[len] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        //int n = sizeof(a) / sizeof(a[0]);
        //  printf("%d\n", n);
        //printf("%d", 1 > 1);
        for (int i = 0; i < len; i++)
        {
            printf("a[%d]=%p ", i, &a[i]);
        }
        qsort(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]), compare);
        //int *l = &a[0];
        //printf("%p %p %p %p\n", &a, &a[1], &a[7], &a[8]);
        //printf("%p %p\n", l++, r--);
        //printf(" %d ", *r);
        // printf("%p %p", l, r);
        // sq(a, (sizeof(a) - 1) / sizeof(a[0]), sizeof(int));
        // int c = rand() % (r + 1 - l) + l;
        //  printf("%p,%p", )
    }
