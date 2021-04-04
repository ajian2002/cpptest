#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

struct strbuf
{
    size_t len;  //当前缓冲区大小
    size_t size; //当前缓冲区容量
    char *buf;   //缓冲区
};


//确保len之后至少有此数量的未使用内存可用 。当您知道要添加的内容的典型大小并希望避免重复自动调整底层缓冲区的大小时，将使用此方法。这从来都不是必需的操作，但在某些情况下对于性能至关重要。
void strbuf_grow(struct strbuf *mybuf, size_t amount);

//初始化结构。如果要防止进一步的重新分配，第二个参数可以为零或更大的数字来分配内存。
void strbuf_init(struct strbuf *mybuf, size_t n);

//释放字符串缓冲区及其使用的内存。使用此函数后，请勿使用字符串缓冲区，除非再次对其进行初始化。
void strbuf_release(struct strbuf *mybuf);

//从strbuf分离字符串并返回它；您现在拥有该字符串占用的存储空间，从那时起，您需要负责在完成处理后使用free（3）释放该字符串。   sz是返回字符串的长度
char *strbuf_detach(struct strbuf *mybuf, size_t *sz);

//将字符串附加到缓冲区。您应该指定要附加的字符串，字符串的当前长度以及分配的内存量。该数量必须大于字符串长度，因为您传递的字符串应该是NUL终止的字符串。必须对该字符串进行malloc（）处理，并且在附加之后，就不能再依赖指针了，也不能直接对指针进行free（）d处理。
void strbuf_attach(struct strbuf *mybuf, void *str, size_t len, size_t mem);

//交换两个字符串缓冲区的内容。
static inline void strbuf_swap(struct strbuf *a, struct strbuf *b);

//确定已分配但未使用的内存的数量。
static inline size_t strbuf_avail(const struct strbuf *sb);

//将缓冲区的长度设置为给定的值。这个函数不会分配新的内存，所以您不应该执行长度大于 len + strbuf _ avail ()的 strbuf _ setlen ()。Strbuf _ setlen ()只是意味着请修复我刚刚弄乱的这个 strbuf 的不变量。
static inline void strbuf_setlen(struct strbuf *sb, size_t len);

//通过将缓冲区的大小设置为零来清空缓冲区。
#define strbuf_reset(mybuf) strbuf_setlen(mybuf, 0)

//字符串去掉空格。
void strbuf_trim(struct strbuf *sb);

//从字符串末尾去掉空格。
void strbuf_rtrim(struct strbuf *sb);

//从字符串开头去掉空格。
void strbuf_ltrim(struct strbuf *sb);

//比较两个缓冲区。如果发现第一个缓冲区分别小于、等于或大于零，则返回小于、匹配或大于第二个缓冲区的整数。
int strbuf_cmp(const struct strbuf *first, const struct strbuf *second);

//向缓冲区添加一个字符。
static inline void strbuf_addch(struct strbuf *sb, int c);

//将数据插入到缓冲区的给定位置。其余内容将被移位，而不是覆盖。
void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len);

//从缓冲区的给定位置移除给定数量的数据。
void strbuf_remove(struct strbuf *sb, size_t pos, size_t len);

//删除 pos. pos + len 之间的字节，并用给定的数据替换它。
void strbuf_splice(struct strbuf *sb, size_t pos, size_t len, const void *data, size_t data_len);

//将给定长度的数据添加到缓冲区。
void strbuf_add(struct strbuf *sb, const void *data, size_t len);

//向缓冲区添加以 null 结尾的字符串。
static inline void strbuf_addstr(struct strbuf *sb, const char *s);

//在当前缓冲区的末尾复制另一个缓冲区的内容。
void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2);

//将缓冲区的一部分从给定位置复制到给定长度的缓冲区末尾。
void strbuf_adddup(struct strbuf *sb, size_t pos, size_t len);

//从指向缓冲区的 FILE * 指针读取给定大小的数据。
size_t strbuf_fread(struct strbuf *sb, size_t size, FILE *file);

//读取给定文件描述符的内容。第三个参数可以用来给出关于文件大小的提示，以避免 reallocs。
ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint);

//读取由文件路径指定的文件内容。第三个参数可以用来给出关于文件大小的提示，以避免 reallocs。
ssize_t strbuf_read_file(struct strbuf *sb, const char *path, size_t hint);

//从 FILE * 指针中读取一行。第二个参数指定行结束符，通常是 n。
int strbuf_getline(struct strbuf *sb, FILE *fp);
