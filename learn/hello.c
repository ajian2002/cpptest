#include <stdio.h>

#include <string.h>
int main()
{
    char *buf = "sahhjfaf&&asdas&&s";char *p =NULL;
    if ((p= strstr(buf, "&&")) != NULL)
    {
        printf("%d", (int)(p - buf));
    }
}
/*
#include <stdio.h>
int main()
{
    printf("hello %s\n", s);
}*/
