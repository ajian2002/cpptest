1. 查看一个int类型数的二进制表示(要求:不进制转换)
2. 向函数传递二维数组的方法(二维数组列数不是常量)


答案:
1.
void printfbin(int num)
{
    for(int i = 31; i >=0;i--)
    {
        if((1<<i)&num)
        printf("1");
        else
        printf("0");
        if(i%8==0)
        printf(" ");
    }
}
2.
a[i][j]= *((int*)a+lie*i+j)



