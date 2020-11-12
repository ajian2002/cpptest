#include <stdio.h>
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
}
8
int add(int *x, int y)
{
    return *x = (*x ^ y);
}
int a;*/
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
    /* 8
    int b = 2020;
    if (add(&b, 1)) //2020   0
    {
        printf("XiyouLinuxGroup%d\n", b);
        printf("Waiting for y%du!\n", a);
    }
    /* if (add(&b, 1) && a++)
    {
        printf("XiyouLinuxGroup%d\n", b);
        printf("Waiting for y%du!\n", a);
    }*/
    /*9
    int a = 1;
    unsigned int c = &a;
    scanf("%d", (int *)c);
    printf("%d", a);
*/
    // char *s[] = {0x6F796958, 0x6E694C75, 0x72477875, 0x3270756F, 0x00313230, 0x00000A};
    //puts(s);
    char str[12];
    fgets(str, 12, stdin);
    //puts(str);
    //   printf("%d", sizeof(str));
    
}
