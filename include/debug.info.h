#include <arpa/inet.h>
#include <bits/sockaddr.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <time.h>
#include <pthread.h>
#include <sys/epoll.h>

#ifdef DEBUGPRINT
#define DEBUGPRINT(format, ...)                                        \
  printf("[%s][%s][%d]" format "\n", __FILE__, __FUNCTION__, __LINE__, \
         ##__VA_ARGS__);

#else
#define DEBUGPRINT(format, ...)
#endif

#if defined MYERROR || defined PRINTEXIT
#define PRINTEXIT(format, ...)                                                 \
  {                                                                            \
    fprintf(stderr,                                                            \
            "[%s][%s][%d]" format ":%s"                                        \
            "\n",                                                              \
            __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__, strerror(errno)); \
    exit(-1);                                                                  \
  }
#else
#define PRINTEXIT(format, ...)
#endif

#ifdef WRITE_LOG
#define WRITE_LOG(filename, FORMAT, ...)                                  \
  {                                                                       \
    FILE *fp = fopen(filename, "a+");                                     \
    struct tm *pt;                                                        \
    time_t timer;                                                         \
    time(&timer);                                                         \
    pt = localtime(&timer);                                               \
    fprintf(fp, "[%04d-%02d-%02d][%02d:%02d:%02d][%s][%s][%2d]" FORMAT,   \
            pt->tm_year + 1900, pt->tm_mon + 1, pt->tm_mday, pt->tm_hour, \
            pt->tm_min, pt->tm_sec, __FILE__, __FUNCTION__, __LINE__,     \
            ##__VA_ARGS__);                                               \
    fclose(fp);                                                           \
  }
#else
#define WRITE_LOG(filename, FORMAT, ...)
#endif