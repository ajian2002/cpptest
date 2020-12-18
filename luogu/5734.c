#include <stdio.h>
#include <string.h>
int main()
{
    char s[500];
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        if (num == 1)
        {
            len = strlen(s);
            char s1[500];
            memset(s1, '\0', 400);
            scanf("%s", s1);
            strcat(s, s1);
            printf("%s", s);
        }
        else if (num == 2) //2qi 3fu 2 3 4 //1 2 3
        {                  //void *memcpy(void *dest, const void *src, size_t n)
            int be, en;
            len = strlen(s);
            char s1[500];
            memset(s1, '\0', 400);

            scanf("%d%d", &be, &en);
            memcpy(s1, (char *)s + be, en);
            printf("%s", s1);
            memset(s, '\0', len + 1);
            memcpy(s, s1, en);
        }
        else if (num == 3)
        {
            int be;
            len = strlen(s);
            scanf("%d", &be);
            char s1[500], s2[500];
            memset(s1, '\0', 400);
            memset(s2, '\0', 400);
            scanf("%s", s1);
            memcpy(s2, s, be);
            strcat(s2, s1);
            int len2 = strlen(s2);
            memcpy((char *)s2 + len2, (char *)s + be, len - be);
            printf("%s", s2);
            len2 = strlen(s2);
            memcpy(s, s2, len2);
            //puts
            //printf("%s", s);
        }
        else if (num == 4)
        {
            len = strlen(s);
            char s1[500];
            memset(s1, '\0', 400);
            scanf(" %s", s1);

            char *p = strstr(s, s1);
            // printf("%s", p);

            int len2 = p - s;
            if (p == NULL)
            {
                printf("-1");
            }
            else
            {
                printf("%d", len2);
            }
        }
        printf("\n");
    }
}