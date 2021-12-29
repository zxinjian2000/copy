#include "pcpy.h"

int main(int argc , char ** argv)
{
	
	int pos = atoi(argv[4]);
	int blocksize = atoi(argv[3]);
	char buffer[blocksize];
	bzero(buffer,sizeof(buffer));
	int sfd = open(argv[1],O_RDONLY);
	int dfd = open(argv[2],O_WRONLY|O_CREAT,0664);
	lseek(sfd,pos,SEEK_SET);
	lseek(dfd,pos,SEEK_SET);
	printf("Copy CPro Pid [%d] pos [%d] block [%d]\n",getpid(),pos,blocksize);
	int rsize;
	rsize = read(sfd,buffer,sizeof(buffer));
	write(dfd,buffer,rsize);
	printf("拷贝完毕\n");
	return 0;
}
