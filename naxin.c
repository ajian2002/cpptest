#include <stdio.h> //大小端深刻理解
#include <string.h>
/*2
int s = 2;
void function()
{
    static int m = 0;// quan
    int n = 0;
    if (s)
    {
        m++;
        n++;
        printf("%d %d\n", m, n);
        s--;
        function();
    }
}*/
int main()
{
    /*1
    unsigned char a = 255;
    char b = 128; //128>127
    a -= b;
    printf("%x,%d\n", b, a); 
    */
    //2 function();
    /*3          AAA
    int A = 65;
    unsigned int f = 33554433;
    *(int *)&f >>= 24;
    *(int *)&f = *(int *)&f + '?'; //63

    printf("%c", A);
    */
    /*4
    int a[2][2];
    printf("%p\n%p\n%p\n%p\n", &a[0][0], &a[0][1], &a[1][0], &a[1][1]);
    printf("%p,%p,%p\n", &a + 1, &a[0] + 1, &a[0][0] + 1);// next      10    01
    */
   
}
