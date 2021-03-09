#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int compare(const void *a, const void *b) //待优化
{
    return ((*(int *)(a)) > (*(int *)(b)));
}
void swapany(void *a, void *b, int size) //交换任意类型的数据//两种交换方法
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
*/
}
void qsort(void *p, size_t count, size_t size, int (*compare)(const void *a, const void *b))
{
    if (count > 1)
    {
        /* code */

        int c = (rand() % (count)) * size;
        //  int temp = *(int *)((char *)p + c);
        //  printf("%d\n", c/size);
        //printf("\n%d  \n", temp);
        swapany(p, ((char *)p + c), size);
        int jj = size;
        int kk = size;
        for (; kk < count * size; kk += size)
        {
            if (compare((char *)p + kk, p))
            {
                //printf("\n 1 \n");
                swapany((char *)p + jj, (char *)p + kk, size);
                //  printf("1");
                jj += size;
                //printf("\n%d\n", jj / size);
            }
            // printf("%d ", kk / size);
        }
        //  printf("\n%d", jj / size); //第jj+1个小于temp
        //swapany(p, (char *)p + jj, size);
        /* code */
        /*   for (int i = 0; i < count; i++)
            printf("%d ", p[i]);
        printf("%d\n", jj / size);

*/
        qsort(p, jj / size, size, compare);
        qsort(((char *)p + jj), count - jj / size, size, compare);
        //这个(int*)很重要很重要
    }
}
int main()
{
    // qsort();
    int len = 10;
    srand((unsigned)time(NULL));
    // srand((unsigned int)time(NULL));

    int a[len];
    // int a[len] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < len; i++)
        a[i] = rand() % 10;

    //int n = sizeof(a) / sizeof(a[0]);
    //printf("%d\n", n);
    //printf("%d", 1 > 1);
    //for (int i = 0; i < len; i++)
    //  printf("a[%d]=%p ", i, &a[i]);
    //printf("\n");
    for (int i = 0; i < len; i++)
        printf("%d ", a[i]);

    printf("\n");
    // printf("%d", sizeof(a) / sizeof(a[0]));
    qsort(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]), compare);
    //  for (int i = 0; i < len; i++)
    //    printf("a[%d]=%p ", i, &a[i]);
    //  printf("\n");
    for (int i = 0; i < len; i++)
        printf("%d ", a[i]);
    //int *l = &a[0];
    //printf("%p %p %p %p\n", &a, &a[1], &a[7], &a[8]);
    //printf("%p %p\n", l++, r--);
    //printf(" %d ", *r);
    // printf("%p %p", l, r);
    // sq(a, (sizeof(a) - 1) / sizeof(a[0]), sizeof(int));
    // int c = rand() % (r + 1 - l) + l;
    //  printf("%p,%p", )
}
