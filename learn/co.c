#include <stdio.h>
#include <stdlib.h>

#include "color.h"

int print_test(void)
{
    printf("This is a character control test!\n");
    printf("\033[1;33m Hello World. \033[0m \n"); //打印黄色的Hello World.

    printf("[%2u]" CLEAR "CLEAR\n" NONE, __LINE__); //以上清空
    printf("This is a character control test!\n");
    printf("\033[1;33m Hello World. \033[0m \n"); //打印黄色的Hello World.

    printf("[%2u]" BLACK "BLACK " L_BLACK "L_BLACK\n" NONE, __LINE__);
    printf("[%2u]" RED "RED " L_RED "L_RED\n" NONE, __LINE__);
    printf("[%2u]" GREEN "GREEN " L_GREEN "L_GREEN\n" NONE, __LINE__);
    printf("[%2u]" BROWN "BROWN " YELLOW "YELLOW\n" NONE, __LINE__);
    printf("[%2u]" BLUE "BLUE " L_BLUE "L_BLUE\n" NONE, __LINE__);
    printf("[%2u]" PURPLE "PURPLE " L_PURPLE "L_PURPLE\n" NONE, __LINE__);
    printf("[%2u]" CYAN "CYAN " L_CYAN "L_CYAN\n" NONE, __LINE__);
    printf("[%2u]" GRAY "GRAY " WHITE "WHITE\n" NONE, __LINE__);
    printf("[%2u]" BOLD "BOLD\n" NONE, __LINE__);
    printf("[%2u]" UNDERLINE "UNDERLINE\n" NONE, __LINE__);
    printf("[%2u]" BLINK "BLINK\n" NONE, __LINE__);
    printf("[%2u]" REVERSE "REVERSE\n" NONE, __LINE__);
    printf("[%2u]" HIDE "HIDE\n" NONE, __LINE__);

    printf(L_RED "L_RED\n" NONE);
    printf(BROWN "heeee\n" NONE);

    return 0;
}

int main()
{
    print_test();
    printf(L_BLUE "%s" NONE, "%-s", "ppp");
    return 0;
}