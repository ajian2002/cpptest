/*#include <stdio.h>
#include <stdlib.h>
*/
#include "doulinklist.h"
int main()
{
    printf("1");
    linklist *one = creaklink(1, 0);
    pushlink(one, 5);
    seelink(one);
    dellink(one);
}