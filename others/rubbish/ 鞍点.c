#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
int main()
{
    int n;
    int count = 0;

    int ra, ca, rb, cb;
    scanf("%d", &n);

    int **A = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        A[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    int tempa[100];
    int tempb[100];
    int tempc[100];
    int maxlie, flag;
    int minhang;
    flag = 0;
    for (int i = 0; i < n; i++)
    {
        int hangmaxval = 0;
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] > hangmaxval)
                hangmaxval = A[i][j];
        } //maxvalue
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == hangmaxval) //行最大
            {

                int lieminval = 1000000; ///列最小
                for (int k = 0; k < n; k++)
                {

                    if (A[k][j] < lieminval)
                        lieminval = A[k][j];
                } //minvalue

                if (A[i][j] == lieminval)
                {
                    printf("%d %d", i, j);
                    flag = 1;
                    goto wcc;
                }
            }
        }
    }
    if (flag == 0)
    {
        printf("NONE");
    }
wcc:
    for (int i = 0; i < n; i++)
    {
        free(A[i]);
    }
    free(A);
    return 0;
}