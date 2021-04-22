#ifdef DEBUG
#define DEBUGPRINT(format, ...) printf("[%s][%s][%d]" format "\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);

#else
#define DEBUGPRINT(format, ...)
#endif

#ifdef MYERROR
#define PRINTEXIT(format, ...)                                                               \
	{                                                                                        \
		printf("[%s][%s][%d]" format "\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
		exit(-1);                                                                            \
	}
#else
#define PRINTEXIT(format, ...)
#endif

#define WRITE_LOG(filename, FORMAT, ...) \
	{\
	FILE *fp = fopen(filename, "a+");\
	struct tm *pt;\
	time_t timer;\
	time(&timer);\
	pt = localtime(&timer);\
	fprintf(fp, "[%04d-%02d-%02d][%02d:%02d:%02d][%s][%s][%2d]" FORMAT, pt->tm_year + 1900, pt->tm_mon + 1, pt->tm_mday, pt->tm_hour, pt->tm_min, pt->tm_sec, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);\
	fclose(fp);\
	}
