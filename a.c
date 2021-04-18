#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void move(int *from, int *fsize, int *to, int *tosize)
{
    to[*tosize] = from[*fsize - 1];
    from[*fsize - 1] = -1;
    *fsize = *fsize - 1;
    *tosize = *tosize + 1;
}

void fun(int n, int *from, int *fsize, int *help, int *hsize, int *to, int *tosize)
{
    if (n == 1)
    {
        move(from, fsize, to, tosize);
    }
    else
    {
        fun(n - 1, from, fsize, to, tosize, help, hsize);
        //	*tosize+=n-1;
        //	*fsize-=n-1;

        move(from, fsize, to, tosize);

        fun(n - 1, help, hsize, from, fsize, to, tosize);
        //	*hsize+=n-1;
        //	*tosize-=n-1;
    }
}

void hanota(int *A, int *ASize, int *B, int *BSize, int *C, int *CSize)
{
    int *temp = C;
    int n = *ASize;
    //temp=(int*)malloc(sizeof(int)*ASize);
    // for(int i=0;i<ASize;i++)
    // {
    //     C[i]=(int*)malloc(sizeof(int));
    //     C[i][0]=0;
    // }
    //memset(temp,0,sizeof(int)*ASize)

    fun(n, A, ASize, B, BSize, temp, CSize);
    //*CSize=ASize;
}
int main()
{
    int A[20];
    int B[20];
    int C[20];
    int t1 = 20, t2 = 0, t3 = 0;
    for (int i = 0; i < t1; i++)
    {
        A[i] = i + 1;
        B[i] = -1;
        C[i] = -1;
    }
    hanota(A, &t1, B, &t2, C, &t3);
    for (int i = 0; i < t3; i++)
        printf("c[%d]-->%d\n", i, C[i]);
    return 0;
}
