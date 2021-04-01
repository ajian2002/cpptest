#include <sys/wait.h>
#include<stdio.h>
int main()
{
	pid_t pid;
	int i;
	for(i;i<2;i++)
	{	pid=fork();
		if(pid<0)
		{
			perror("fork failed");exit(-1);
		}
		else if(pid==0)
			break;
	}
	if(i==0)//兄
	{}
	if(i==1)//弟
	{}
	if(i==2)//父
	{}
	




