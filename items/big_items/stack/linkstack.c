#include "linkstack.h"
//#define shunstack struct linkstack
//#define _stack _struct linkstack
int main()
{
    struct linkstack *S = init_stack(5);

    push_stack(S, 4);
    see_stack(S);
    push_stack(S, -2);
    push_stack(S, 8);
    push_stack(S, -2);
    push_stack(S, 8);
    see_stack(S);
    push_stack(S, 8);
    see_stack(S);
    pop_stack(S);
    see_stack(S);
    pop_stack(S);
    //push_stack(S, 4);
    see_stack(S);
    del_stack(S);
}