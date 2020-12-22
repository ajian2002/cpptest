#include "shunxustack.h"

int main()
{
    shunstack *S = init_stack();
    see_stack(S);
    push_stack(S, 4);
    push_stack(S, -2);
    push_stack(S, 8);
    push_stack(S, -2);
    push_stack(S, 8);
    see_stack(S);
    push_stack(S, 8);
    pop_stack(S);
    see_stack(S);
    pop_stack(S);
    pop_stack(S);
    pop_stack(S);
    pop_stack(S);
    // push_stack(S, 4);
    see_stack(S);
    printf("栈顶为%d\n", get_top(S));
    printf("栈内有%d个元素\n", len_stack(S));
    clr_stack(S);
    if (isclr_stack(S))
        printf("栈空\n");
    else
    {
        printf("栈内有元素\n");
    }

    del_stack(S);
}