#include <stdlib.h>
#include <stdio.h>
#define DEBUGPRINT
//#undef DEBUGPRINT
#include "debug.info.h"

int main()
{
  char*s="abc";
  DEBUG("123");
  DEBUG("%s", s);
  //printf("%s\n");

  
  s[0] = '\0';
  printf("%s\n", s);
	
  return 0;
}
