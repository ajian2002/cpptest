#include <cstddef>
#include <stdlib.h>
#include <string.h>
size_t getline1(char **lineptr, size_t *n, FILE *stream);

size_t getline1(char **lineptr, size_t *n, FILE *stream)
{

    fgets(*lineptr, *n, stream);
    size_t len = strlen(*lineptr);
    if ((*lineptr)[len - 1] != '\n')
    {
        realloc(*lineptr, sizeof(stream));
        fgets(*lineptr, *n, stream);
    }

    //*lineptr = (char *)stream;
    return len;
}