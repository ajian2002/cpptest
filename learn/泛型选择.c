#define  GETTYPE(x) _Generic(x,\
int:"int",\
double:"double",\
default:"other"\
)
#include<stdio.h>
#include<string.h>
int main()
{
    //double x=1;
    void*x=NULL;
    if(strcmp("int",GETTYPE(x))==0)
    printf("%d\n",x);
    else if(strcmp("double",GETTYPE(x))==0)
    printf("%f\n",x);
    else if(strcmp("other",GETTYPE(x))==0)
    printf(GETTYPE(x));
}
