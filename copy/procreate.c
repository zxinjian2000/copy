#include "pcpy.h"
#include <sys/types.h>
#include <sys/wait.h>
int procreate(const char * SFile ,const char * DFile , int pronum , int blocksize)
{
	int flag;
	pid_t pid;
	int pos;
	char cblock[10];
	char cpos[10];
	bzero(cblock,sizeof(cblock));
	bzero(cpos,sizeof(cpos));
	for(flag = 0;flag < pronum;flag++)
	{
		pid = fork();
		if(pid == 0)
			break;
	}
	if(pid >0)
	{
		printf("parent pro pid [%d] 非阻塞回收 \n",getpid());
		pid_t zpid;
		while((zpid = waitpid(-1,NULL,WNOHANG))!= -1)
		{
			if(zpid>0)
				printf("parent wait success:zombie pid [%d]\n",zpid);
		}
	}
	else if(pid ==0)
	{
		pos = flag*blocksize;
		printf(cblock,"%d",blocksize);
		printf(cpos,"%d",pos);
		execl("/home/colin/5/copydemo/copy","copy",SFile,DFile,cblock,cpos,NULL);
	}
	else
	{
		perror("fork call failed");
		exit(-1);
	}
}
