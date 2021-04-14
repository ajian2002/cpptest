#include <my/debug.info.h>
char *KMP(char *s1, char *s2)
{
    //strstr(s1,s2);
    int M = strlen(s1);
    int N = strlen(s2);
    int i = 0, j = 0;
    //temp[N][256]
    int **temp = (int **)malloc(sizeof(int *) * N);
    for (i = 0; i < N; i++)
        temp[i] = (int *)calloc(256, sizeof(int));
    temp[0][s1[0]] = 1;
    int x = 0;
    int c = 0;

    for (j = 1; j < N; j++)
    {
        for (c = 0; c < 256; c++)
        {
            if (s2[j] == c)
                temp[j][c] = j + 1;
            else
                temp[j][c] = temp[x][c];
            ///temp[j][c] = temp[x][c];
        }
        //temp[j][s2[j]] = j + 1;
        x = temp[x][s2[j]];
    }

    //search
    j=0;
    for (i = 0; i < M; i++)
    {
        j = temp[j][s1[i]];
        if (j == N)
            return &s1[i - N + 1];
    }

    return NULL;
}

int main()
{
    char *s1 = "01010011100100100000011010100011010101010";
    char *s2 = "010101";
    char *s3 = NULL;
    s3 = strstr(s1, s2);
    if (s3 != NULL)
    {
        printf("strstr:%d\n", (int)(s3 - s1));
    }

    char *s4 = NULL;
    char *temp = NULL;
    temp = KMP(s1, s2);
    s4 = temp;
    //s4 = search(temp, s2);
    if (s4 != NULL)
    {
        printf("KMP:%d\n", (int)(s4 - s1));
    }
    else
    {
        printf("NULL\n");
    }

    return 0;
}