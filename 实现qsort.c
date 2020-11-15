#include <stdio.h> //大至小
#define NUM 1000
//void qsort(int *p, int l, int r);
void qsort(void *p, size_t n, size_t size, int (*compare)(const void *, const void *));
//int compare(const void *a, const void *b);
int compare(const void *a, const void *b);
int main()
{
    int a[NUM] = {0};
    int i = 0, n = 0;
    //printf("输入数目个数");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    //int l = 0;
    //int r = n - 1;

    //qsort(a, l, r);
    qsort(a, n, sizeof(int), compare);
    //printf("%p %p\n", &a, &(a + n));
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
void qsort(void *p, size_t n, size_t size, int (*compare)(const void *, const void *))
{
    //
    int *ll = (int *)&p;
    int *l = (int *)&p;
    int *rr = (int *)(((size_t)&p + (n - 1) * sizeof(size)));
    int *r = (int *)(((size_t)&p + (n - 1) * sizeof(size)));

    //int l = *p;
    //int r = *p[n-1];

    if (l < r)
    {
        int temp = *(int *)p;
        while (l != r)
        {
            while (l < r && *r >= temp)
                r--;
            // if (l != r)
            //  p[l] = p[r];
            *l = *r;
            while (l < r && *l <= temp)
                l++;
            //if (l != r)
            *r = *l;
        }
        if (r == l)
            *((int *)*r) = temp;

        qsort(r, (int)(rr - *r), sizeof(size), compare);
        qsort(ll, (int)(r - *ll), sizeof(size), compare);
    }
}
