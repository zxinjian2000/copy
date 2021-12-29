#include "pcpy.h"

int block(const char * SFile , int pronum)
{
	int FileSize;
	int fd = open(SFile,O_RDONLY);
	FileSize = lseek(fd,0,SEEK_END);
	if(FileSize % pronum == 0)
		return FileSize / pronum;
	else
		return FileSize / pronum + 1;
}
