#include<stdio.h>
int main(){
    int s[10][10]={{0}};
    for(int i = 0; i <10;i++)
    {
        for (int j =0;j < 10; j++)
        printf("%d ",s[i][j]);
        printf("\n");
    }
}