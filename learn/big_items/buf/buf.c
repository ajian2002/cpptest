
#include "buf.h"

void strbuf_grow(struct strbuf *mybuf, size_t amount) //okk
{
    if (!mybuf)
    {
        exit(0);
    }
    if (!mybuf->buf)
    {
        mybuf->buf = (char *)malloc(amount * sizeof(char));
        mybuf->len = 0;
        mybuf->size = amount;
        memset(mybuf->buf, '\0', amount);
        return;
    }
    else if (amount <= 0)
    {
        return;
    }
    else if (mybuf->size - mybuf->len - 1 < amount)
    {
        if (mybuf->len == 0)
        {
            mybuf->buf = (char *)realloc(mybuf->buf, amount);
            mybuf->size = amount;
            memset(mybuf->buf, '\0', mybuf->size);
        }
        else
        {
            mybuf->buf = (char *)realloc(mybuf->buf, mybuf->len + 1 + amount);
            mybuf->size = mybuf->len + 1 + amount;
            memset(&mybuf->buf[mybuf->len + 1], '\0', amount);
        }
    }
}

void strbuf_init(struct strbuf *mybuf, size_t n) //ok
{
    mybuf->len = 0;
    mybuf->size = 0;
    if (n == 0)
    {
        n = 1;
        assert(n == 1);
    }
    else if (n < 0)
    {
        //printf("init error \n");
        exit(1);
    }
    mybuf->buf = (char *)malloc(sizeof(char) * n);
    //c[n - 1] = '\0';
    memset(mybuf->buf, '\0', n);
    mybuf->size = n;
}

void strbuf_release(struct strbuf *mybuf) //ok
{
    if (mybuf->buf)
    {
        free(mybuf->buf);
        mybuf->buf = NULL;
    }
    mybuf->size = 0;
    mybuf->len = 0;
    //assert(mybuf->buf == NULL);
}

char *strbuf_detach(struct strbuf *mybuf, size_t *sz) //ok
{

    char *temp = (char *)malloc(sizeof(char) * (mybuf->len + 1));
    memcpy(temp, mybuf->buf, mybuf->len + 1);
    *sz = mybuf->len;
    strbuf_release(mybuf);
    strbuf_init(mybuf, 0);
    return temp;
}

void strbuf_attach(struct strbuf *mybuf, void *str, size_t len, size_t mem) //ok
{

    if (mybuf->len == 0)
    {
        strbuf_grow(mybuf, len);
        memcpy(mybuf->buf, str, len);
        mybuf->buf[len] = '\0';
        mybuf->len = len;
    }
    else
    {
        strbuf_grow(mybuf, len + 1);
        memcpy(&(mybuf->buf[mybuf->len + 1]), str, len + 1);
        mybuf->len = len + 1 + mybuf->len;
        //mybuf->size += len + 1;
    }
    free(str);
}

static inline void strbuf_swap(struct strbuf *a, struct strbuf *b) //ok
{
    char *temp = a->buf;
    a->buf = b->buf;
    b->buf = temp;
    size_t tem = a->size;
    a->size = b->size;
    b->size = tem;
    tem = a->len;
    a->len = b->len;
    b->len = tem;
}

static inline size_t strbuf_avail(const struct strbuf *mybuf) //ok
{
    if (mybuf->len != 0)
        return mybuf->size - mybuf->len - 1;
    else
        return mybuf->size - mybuf->len;
}

static inline void strbuf_setlen(struct strbuf *mybuf, size_t len) //ok
{
    if (len + 1 <= mybuf->size)
        mybuf->len = len;
    else
        exit(0);
}

void strbuf_trim(struct strbuf *mybuf) //ok
{
    strbuf_rtrim(mybuf);
    strbuf_ltrim(mybuf);
    /*for (int i = 0; i < mybuf->len; i++)
    {
        if (mybuf->buf[i] == ' ')
        {
            memmove(&mybuf->buf[i], &mybuf->buf[i + 1], mybuf->len - i - 1);
            mybuf->buf[mybuf->len - 1] = '\0';
            mybuf->len -= 1;
            i -= 1;
        }
    }*/
}

void strbuf_rtrim(struct strbuf *mybuf) //ok
{
    int j = 0;
    //printf("%ld\n", mybuf->len);
    for (int i = mybuf->len - 1; i > -1; i--)
    {
        //printf("%d\n", i);
        if (mybuf->buf[i] != ' ')
        {
            j = i;
            break;
        }
    }
    //printf("%d\n", j);
    mybuf->buf[j + 1] = '\0';
    //char *temp = strbuf_detach(mybuf, &j);

    //mybuf->buf = temp;
    mybuf->len = j + 1;
    //mybuf->size = j + 1;
}

void strbuf_ltrim(struct strbuf *mybuf) //ok
{
    int j = 0;
    for (int i = 0; i < mybuf->len; i++)
    {
        if (mybuf->buf[i] != ' ')
        {
            break;
        }
        else
        {
            j++;
        }
    }
    //j
    memmove(mybuf->buf, &(mybuf->buf[j]), mybuf->len - j);
    mybuf->buf[mybuf->len - j] = '\0';
    mybuf->len -= j;
}

int strbuf_cmp(const struct strbuf *first, const struct strbuf *second) //ok
{
    if (first->size > second->size)
    {
        return 1;
    }
    else if (first->size == second->size)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

static inline void strbuf_addch(struct strbuf *mybuf, int c) //ok
{
    strbuf_grow(mybuf, 1);
    mybuf->buf[mybuf->len] = c;
    mybuf->buf[mybuf->len + 1] = '\0';
    mybuf->len++;
}

void strbuf_insert(struct strbuf *mybuf, size_t pos, const void *data, size_t len) //ok
{
    //pos 0-->first
    strbuf_grow(mybuf, len);

    //3  4
    memmove(&mybuf->buf[pos + len], &mybuf->buf[pos], mybuf->len - pos + 1);
    memcpy(&mybuf->buf[pos], data, len);
    mybuf->len += len;
    //seeediff(mybuf);
}

void strbuf_remove(struct strbuf *mybuf, size_t pos, size_t len) //okk
{
    memmove(mybuf->buf + pos, mybuf->buf + pos + len, mybuf->len - pos - len);

    mybuf->len -= len;
    mybuf->buf[mybuf->len] = '\0';
}

void strbuf_splice(struct strbuf *mybuf, size_t pos, size_t len, const void *data, size_t data_len) //ok
{
    strbuf_remove(mybuf, pos, len);
    strbuf_insert(mybuf, pos, data, len);
}

void strbuf_add(struct strbuf *mybuf, const void *data, size_t len) //okk
{
    strbuf_grow(mybuf, len);
    strbuf_insert(mybuf, mybuf->len, data, len);
}

static inline void strbuf_addstr(struct strbuf *mybuf, const char *s) //ok
{
    strbuf_grow(mybuf, strlen(s) + 1);
    strbuf_add(mybuf, s, strlen(s));
}

void strbuf_addbuf(struct strbuf *first, const struct strbuf *second) //ok
{
    int temp = first->size;
    //printf("%ld", strbuf_avail(first));
    strbuf_grow(first, second->size + strbuf_avail(first));
    memcpy(first->buf + temp, second->buf, second->size);
    //first->size += second->size;
}

void strbuf_adddup(struct strbuf *mybuf, size_t pos, size_t len) //ok
{
    int temp = mybuf->size;
    strbuf_grow(mybuf, len + strbuf_avail(mybuf) + 1);
    memcpy(&mybuf->buf[temp], &mybuf->buf[pos], len);
}

size_t strbuf_fread(struct strbuf *mybuf, size_t size, FILE *file) //ok
{

    //size_t fread( void *restrict buffer, size_t size, size_t count, FILE *restrict stream );

    int temp;

    fseek(file, 0L, SEEK_END);
    long length = ftell(file);
    fseek(file, 0L, SEEK_SET);

    if (size > length)
        size = length;
    if (mybuf->len == 0)
    {
        strbuf_grow(mybuf, size + 1);

        temp = fread(&mybuf->buf[mybuf->len], sizeof(char), size, file);
        mybuf->len += size;
    }
    else
    {
        strbuf_grow(mybuf, size + 1);
        temp = fread(&mybuf->buf[mybuf->len + 1], sizeof(char), size, file);
        mybuf->len += size + 1;
    }

    return temp;
}

ssize_t strbuf_read(struct strbuf *mybuf, int fd, size_t hint) //ok
{
    //ssize_t read(int fd, void * buf, size_t count);
    char *temp = NULL;
    int tt = 0;
    strbuf_grow(mybuf, hint + 1);
    if (mybuf->len == 0)
    {
        temp = mybuf->buf;
        tt = read(fd, temp, hint);
        mybuf->len += tt;
    }
    else
    {
        temp = &mybuf->buf[mybuf->len + 1];
        tt = read(fd, temp, hint);
        mybuf->len += tt + 1;
    }
    
    return tt;
}

ssize_t strbuf_read_file(struct strbuf *mybuf, const char *path, size_t hint) //ok
{
    FILE *fp = fopen(path, "a+");
    return strbuf_fread(mybuf, hint, fp);
}

int strbuf_getline(struct strbuf *mybuf, FILE *fp) //maybe ok
{
    char *buf;
    if (mybuf->len == 0)
    {
        buf = &mybuf->buf[mybuf->len];
        int j = 0;
        int base = 4;
        mybuf->size = base;
        buf = (char *)realloc(buf, sizeof(char) * mybuf->size);

        memset(buf, '\0', base);
        if (buf == NULL)
            exit(1);
        char c;
        c = fgetc(fp);
        while (c != '\n' && c != EOF)
        {
            if (base == j)
            {
                base += 4;
                mybuf->size = base;
                buf = (char *)realloc(buf, sizeof(char) * mybuf->size);
                memset(&buf[j], '\0', 4);
                if (buf == NULL)
                    exit(1);
            }
            buf[j++] = c;
            c = fgetc(fp);
        }
        base += 4;
        mybuf->size = base;
        buf = (char *)realloc(buf, sizeof(char) * mybuf->size);

        if (buf == NULL)
            exit(1);
        buf[j] = '\n';
        mybuf->buf = buf;
        mybuf->len = j + 1;
        memset(&buf[j + 1], '\0', mybuf->size - mybuf->len);
        return j;
    }
    else
    {
        int j = 0;
        int base = 4;
        int size = 4;
        int a = mybuf->len + 1;
        if (strbuf_avail(mybuf) < size)
        {
            mybuf->size = size + a;
            mybuf->buf = (char *)realloc(mybuf->buf, mybuf->size);
            memset(&mybuf->buf[a + j], '\0', size);
        }

        char c;
        c = fgetc(fp);
        while (c != '\n' && c != EOF)
        {
            if (base == j)
            {
                base += size;
                mybuf->len += size;
                if (strbuf_avail(mybuf) < size)
                {
                    int m = strbuf_avail(mybuf);
                    mybuf->size += size;
                    mybuf->buf = (char *)realloc(mybuf->buf, mybuf->size);
                    memset(&mybuf->buf[a + j], '\0', size + m);
                }
                mybuf->buf[a + j] = c;
            }
            else
                mybuf->buf[a + j] = c;
            j++;
            c = fgetc(fp);
        }
        if (base == j)
        {
            mybuf->len += size + 2;
            mybuf->size += 2;
            mybuf->buf = (char *)realloc(mybuf->buf, mybuf->size);
            memset(&mybuf->buf[mybuf->size - 1], '\0', 1);
        }
        else
        {
            mybuf->len += size - base + j + 2;
            mybuf->size += base - j;
            mybuf->buf = (char *)realloc(mybuf->buf, mybuf->size);
            memset(&mybuf->buf[mybuf->size - 1], '\0', 1);
        }
        mybuf->buf[a + j] = c;
        return j;
    }
}
