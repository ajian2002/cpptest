#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#define pipename1 "pipee"
#define BUF_SIZE 1024
int main()
{
	int f;
	int fd;
	char buf[BUF_SIZE] = {0};
	umask(0);
	f = mkfifo(pipename1,0666);
	
	if (f ==-1)
	{
		perror("mkfifo error");
		exit(-1);
	}
	

	fd = open(pipename1, O_WRONLY);
	if (fd == -1)
	{
		perror("open error");
		exit(-1);
	}

	strcpy(buf, "abcabc\n");
	f = write(fd, buf, strlen(buf)+1);
	close(fd);
	
	//goto wwc;
}
