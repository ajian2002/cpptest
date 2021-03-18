#ifndef DEBUGHELPER_HPP
#define DEBUGHELPER_HPP 1

#include <cerrno>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define RED "\033[31m"    //ERROR
#define GREEN "\033[32m"  //INFO
#define YELLOW "\033[33m" //WARN
#define BLUE "\033[34m"   //NOTICE
#define GRAY "\e[0;37m"   //DEBUG
#define CLOSE "\033[0m"

#define ERROR 4
#define WARN 3
#define NOTICE 2
#define INFO 1
#define DEBUG 0
#define __LOCALE__ __FILE__, __LINE__
#define __TARGET__ " %s:%d "
#define Debug(x, y, ...) debug(y __TARGET__, x, errno, __VA_ARGS__, __LOCALE__)

#define DEBUG_MESSAGE_LEM_MAX 256
#define DEBUG_COLOR_BUF 32
#define DEBUG_STRERROR_BUF 64

static FILE *DEBUG_STREAM = stderr;
static inline char *color(const int level, char buf[DEBUG_COLOR_BUF])
{
    switch (level)
    {
    case INFO:
        snprintf(buf, DEBUG_COLOR_BUF, GREEN "[INFO]");
        break;
    case WARN:
        snprintf(buf, DEBUG_COLOR_BUF, YELLOW "[WARN]");
        break;
    case ERROR:
        snprintf(buf, DEBUG_COLOR_BUF, RED "[ERROR]");
        break;
    case NOTICE:
        snprintf(buf, DEBUG_COLOR_BUF, BLUE "[NOTICE]");
        break;
    case DEBUG:
        snprintf(buf, DEBUG_COLOR_BUF, GRAY "[DEBUG]");
        break;
    default:
        buf[0] = '\0';
        break;
    }
    return buf;
}
/* 本函数线程安全 */
inline void debug(const char *message, const int level, const int err)
{
    char colorbuf[DEBUG_COLOR_BUF];
    char errbuf[DEBUG_STRERROR_BUF];
    color(level, colorbuf);
    if (err)
        fprintf(DEBUG_STREAM, "%s%s Reason:%s" CLOSE "\n", colorbuf, message, strerror(err));
    else
        fprintf(DEBUG_STREAM, "%s%s" CLOSE "\n", colorbuf, message);
}
/* 本函数线程安全 */
inline void debug(const int level, const int err, const char *formate, ...)
{
    va_list ap;
    va_start(ap, formate);
    char buf[DEBUG_MESSAGE_LEM_MAX];
    vsnprintf(buf, sizeof(buf), formate, ap);
    va_end(ap);
    debug(buf, level, err);
}

#undef DEBUG_MESSAGE_LEM_MAX
#undef DEBUG_COLOR_BUF
#undef DEBUG_STRERROR_BUF
#undef RED
#undef GREEN
#undef YELLOW
#undef BLUE
#undef GRAY
#undef CLOSE

#endif