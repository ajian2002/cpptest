#ifdef DEBUGPRINT
#define DEBUG(format, ...) printf("File: "__FILE__", Line: %d: "format"\n", __LINE__, ##__VA_ARGS__)   
#else
#define DEBUG(format, ...)
#endif