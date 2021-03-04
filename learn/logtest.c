
#include <stdio.h>
#define MIN(a, b, c)   (((a)>(b))?(b):(a))>(c)?(c):(((a)>(b))?(b):(a));
//#define large(x,y)  if((x) > (y)) ? (y) : (x);
int main(int argc, char **argv)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int d=MIN(a,b,c);
    
    printf("%d", d);
    return 0;
}