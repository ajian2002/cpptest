#include <stdio.h>

int main()
{
    char szDig[] = "10,22m,Z86,,880;555:666.";
    int dwIdx = 0, dwVal = 0, dwSize = 0;
    while (1 == sscanf(szDig + dwIdx, "%d%*[^0-9]%n", &dwVal, &dwSize))
    {
        dwIdx += dwSize;
        printf("dwIdx=%d, dwSize=%d, dwVal=%d\n", dwIdx, dwSize, dwVal);
    }
}
