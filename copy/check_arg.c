#include "pcpy.h"

int check_arg (const char * SFile , int arg_num , int pronum)
{
	if((access(SFile,F_OK))!=0)
	{
		perror("check_arg error");
		exit(-1);
	}
	if(arg_num < 3)
	{
		printf("check_arg error : 参数数量异常！");
		exit(-1);
	}
	if(pronum <= 0 || pronum >= 100)
	{
		printf("check_arg error : 进程数要大于0 小于100 \n");
		exit(-1);
	}
	return 0;
}
