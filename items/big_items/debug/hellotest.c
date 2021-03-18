#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#define DEBUG
//#undef DEBUGPRINT
#include <my/debug.info.h>

int main()
{
	char *s = "abc";
	//  DEBUGPRINT("123");
	//DEBUGPRINT("%s", s);
	//
	if (1)
		WRITE_LOG("log","123%s""\n",s);
	//PRINTEXIT("p || g is NULL \n");

	//PRINTEXIT("%s", s);
	//printf("%s\n");

	//s[0] = '\0';
	printf("%s", s);
	
	//printf("%s\n", s);

	return 0;
}
