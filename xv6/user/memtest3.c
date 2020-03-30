#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
	char *arg;
	int fd = open("tmp", O_WRONLY | O_CREATE );
	if(fd == -1)
	{
		printf(1, "Failed to open\n");
		printf(1, "TEST FAILED\n");
		exit();
		return -1;
	}
	
	
	arg = (char*) 0x0;
	if(write(fd, arg, 10) != -1)
	{
		printf(1, "Null Pointer\n");
		printf(1, "TEST FAILED\n");
		exit();
		return -1;
	}
	
	arg = (char*) 0x400;
	if(write(fd, arg, 1024) != -1)
	{
		
		printf(1, "Null Non-Zero Pointer\n");
		printf(1, "TEST FAILED\n");
		exit();
		return -1;
	}
	
	arg = (char*) 0xfff;
	if(write(fd, arg, 1) != -1)
	{
		printf(1, "Out of bounds");
		printf(1, "TEST FAILED\n");
		exit();
		return -1;
	}
	
	printf(1, "TEST PASSED\n");
	exit();
}