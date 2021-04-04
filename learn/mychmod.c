#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc, char **argv)
{
    int u;
    int g;
    int o;
    char *path;
    if (argc < 3)
    {
        printf("argc less than except");
        exit(0);
    }
    int mode = atoi(argv[1]);
    if (mode > 777 || mode < 0)
    {
        printf("mode error");
        exit(0);
    }
    u = mode / 100;
    g = mode / 10 % 10;
    o = mode % 10;
    mode = u * 8 * 8 + 8 * g + o;

    path = argv[2];
    //printf("%d%d%d\n", u, g, o);
    if (chmod(path, mode) == -1)
    {
        printf("chmod error");
        exit(1);
    }
    return 0;
}