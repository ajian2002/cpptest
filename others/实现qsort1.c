#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//int sfds = 0;
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
        srand((unsigned int)time(NULL));
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
        //void *const di = p;
        //摸索
        // int *j=getdata( p;
        //void *k = p + (count - 1) * size;
        ;
        //  int cc = count;
        //    int dd = count;
        if (count > 1)
        {
            int jj = size;
            // int kk = (count - 1) * size;
            int c = (rand() % count) * size;
            //printf("%d ", c / size);
            void *pp = (char *)p + c;
            swapany((char *)pp, (char *)p, size);
            //int cc = count;
            // int dd = count;
            //int jj = size;
            //int kk = (count - 1) * size;

            /* while (true)
        {
            while (compare((char *)p, (char *)p + jj) < 0)
            {
                jj += size;
                if (jj == kk)
                {
                    break;
                    //break;
                }

                //printf("1");
            }
            while (compare((char *)p, (char *)p + kk) > 0)
            {
                kk -= size;
                if (kk == jj)
                {
                    break;
                    // break;
                }

                //  printf("2");
            }
            swapany((char *)p + jj, (char *)p + kk, size);

            if (jj >= kk)
                break;
            jj += size;
            printf("3");
            //printf("2");
        }
        */
            //int jj = size;
            for (int i = size; i < size * count; i += size)
            {
                if (compare((char *)p, (char *)p + i))
                {
                    swapany((char *)p + i, (char *)p + jj, size);
                    jj += size;
                }
                //printf("q");
            }
            //swapany((char *)p, (char *)p + jj, size);
            //printf("%d", sfds++);
            // for (int i = 0; i < count * size; i += size)
            //   printf("%d ", getdata(p + i));
            /*    for (int i = 0; i < 10 * size; i += size)
            printf(" %d ", *((int *)((char *)di + i)));
        printf("\n");
*/
            qsort((char *)p, jj / size, size, compare);
            qsort((char *)p + jj + size, count - jj / size - 1, size, compare);
        }
    }

    int main()
    {
        //srand((unsigned int)time(NULL));
        //int a[NUM] = {0};
        int i = 0, n = 10;
        //printf("输入数目个数");
        //scanf("%d", &n);
        //int a[n];
        //for (i = 0; i < n; i++)
        //   scanf("%d", &a[i]);

        //int l = 0;
        //int r = n - 1;
        //int n = 10;
        int a[n];
        srand((unsigned)time(NULL));
        for (int i = 0; i < n; i++)
            a[i] = rand() % 10;

        for (int i = 0; i < n; i++)
            printf(" %d ", a[i]);
        printf("\n");

        qsort(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]), compare);
        // printf("\n");
        for (int i = 0; i < n; i++)
            printf(" %d ", a[i]);
        //getchar();
    }
