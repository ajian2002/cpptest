#ifdef DEBUG
#define DEBUGPRINT(format, ...) printf( "File:  "__FILE__",Line: %d :"format"\n",__LINE__, ##__VA_ARGS__)

#else
#define DEBUGPRINT(format, ...) 
#endif



#ifdef MYERROR
#define PRINTEXIT(format, ...) {printf("File:"__FILE__",Line:%d :\n"format"\n",__LINE__, ##__VA_ARGS__);exit(-1);}
#else
#define PRINTEXIT(format, ...); ; 
#endif
