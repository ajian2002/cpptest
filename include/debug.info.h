#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/param.h>
#include <syslog.h>
//System V
#include <sys/msg.h> //消息队列
#include <sys/sem.h> //信号量
#include <sys/shm.h> //共享内存区
//Posix
#include <mqueue.h>	   //消息队列
#include <semaphore.h> //信号量
#include <sys/mman.h>  //共享内存区


#ifdef DEBUG
#define DEBUGPRINT(format, ...) printf("[%s][%s][%d]" format "\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);

#else
#define DEBUGPRINT(format, ...)
#endif

#ifdef MYERROR
#define PRINTEXIT(format, ...)                                                     \
	{                                                                              \
		fprintf(stderr, "[%s][%s][%d]" format ":%s"                                \
						"\n",                                                      \
				__FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__, strerror(errno)); \
		exit(-1);                                                                  \
	}
#else
#define PRINTEXIT(format, ...)
#endif

#define WRITE_LOG(filename, FORMAT, ...)                                                                                                                                                                            \
	{                                                                                                                                                                                                               \
		FILE *fp = fopen(filename, "a+");                                                                                                                                                                           \
		struct tm *pt;                                                                                                                                                                                              \
		time_t timer;                                                                                                                                                                                               \
		time(&timer);                                                                                                                                                                                               \
		pt = localtime(&timer);                                                                                                                                                                                     \
		fprintf(fp, "[%04d-%02d-%02d][%02d:%02d:%02d][%s][%s][%2d]" FORMAT, pt->tm_year + 1900, pt->tm_mon + 1, pt->tm_mday, pt->tm_hour, pt->tm_min, pt->tm_sec, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
		fclose(fp);                                                                                                                                                                                                 \
	}