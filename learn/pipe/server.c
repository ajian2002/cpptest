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
wwc:
	fd = open(pipename1, O_RDONLY);
	if (fd == -1)
	{
		sleep(1);
		goto wwc;
	}
wcc:
	f = read(fd, buf,BUF_SIZE);
	if(!f)
	{
		goto wcc;
	}
	printf("%s\n", buf);
	memset(buf, 0, sizeof(char) * BUF_SIZE);
	close(fd);

	//goto wwc;
}
