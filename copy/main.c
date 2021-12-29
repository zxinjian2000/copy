#include "pcpy.h"

int main(int argc,char ** argv)
{
	int pronum;
	int blocksize;
	if(argv[3]==0)
		pronum=5;
	else
		pronum = atoi(argv[3]);
	check_arg(argv[1],argc,pronum);
	blocksize = block(argv[1],pronum);
	procreate(argv[1],argv[2],pronum,blocksize);
	return 0;
}
