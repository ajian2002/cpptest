#include <stdio.h>
#include <string.h>
#include <math.h>
#define max(a, b) ((a) > (b)) ? (a) : (b)
int add(int n)
{
    int sum = 0;
    for (int j = 0; j < n; j++)
        sum += j;
    return sum;
}
typedef struct asd
{
    int sd : 30;
    char sfdf;
} Asd;
//#undef max
int main()
{
    struct asd p;
    memset(&p, 0, sizeof(p));
    // int i = 100, sum = 0;
    // sum = add(i);
    // printf("%d %d\n", i, sum);
    // i = 1000000;
    // printf("%d\n", max(i, sum));
    // //
    printf("%ld\n", sizeof(p));
}