#include "buf.h"

#define seediff(a)                               \
    printf("size=%ld,len=%ld\n", a.size, a.len); \
    seesize(a);                                  \
    printf("\n");                                \
    seelen(a);                                   \
    printf("\n");

//查看size内容
#define seesize(a)                   \
    for (int i = 0; i < a.size; i++) \
    {                                \
        if (a.buf[i] == '\0')        \
        {                            \
            printf("\\0");           \
            continue;                \
        }                            \
        if (a.buf[i] == ' ')         \
        {                            \
            printf("K");             \
            continue;                \
        }                            \
        if (a.buf[i] == '\n')        \
        {                            \
            printf("\\n");           \
            ;                        \
            continue;                \
        }                            \
        else                         \
            printf("%c", a.buf[i]);  \
    }

//查看len内容
#define seelen(a)                   \
    for (int i = 0; i < a.len; i++) \
    {                               \
        if (a.buf[i] == '\0')       \
        {                           \
            printf("\\0");          \
            continue;               \
        }                           \
        if (a.buf[i] == ' ')        \
        {                           \
            printf("K");            \
            continue;               \
        }                           \
        if (a.buf[i] == '\n')       \
        {                           \
            printf("\\n");          \
            ;                       \
            continue;               \
        }                           \
        else                        \
            printf("%c", a.buf[i]); \
    }

int main()
{
    struct strbuf a, b;
    strbuf_init(&a, 2);
    strbuf_init(&b, 1);
    //printf("%ld\n", strbuf_avail(&a));
    int slen = 7;
    char *str = (char *)malloc(sizeof(char) * slen);
    memcpy(str, "123456", slen);
    //strbuf_addstr(&a, str);
    //strbuf_addstr(&a, str);
    seediff(a);
    //memcpy(str, "abcdef", slen);
    //strbuf_addstr(&b, str);
    //seediff(b);

    //FILE *fp = fopen("/home/ajian/code/WeeklyTasks/6.buf/test.txt", "r");
    /*strbuf_fread(&b, 100, fp);
    seediff(b);
    

    */

    //strbuf_getline(&b, fp);
    //seediff(b);
    free(str);
    //fclose(fp);
    int fd = open("./buftest.txt", O_RDONLY);
    strbuf_read(&a, fd, 4);
    seediff(a);
    strbuf_release(&a);
    strbuf_release(&b);
    return 0;
}