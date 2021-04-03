#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>

int main()
{
	int fd;
	printf("uid %d euid %d\n",getuid(),geteuid());
	fd=open("abc.in",O_RDWR);
	if(fd==-1)
	{
		printf("open failure  %s\n",strerror(errno));
		exit(1);
	}
	else
	{
		printf("open success\n");
	}
	close(fd);
	exit(0);
}


