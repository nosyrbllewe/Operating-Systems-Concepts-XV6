#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
	int i = 1;
	for(i = 1; i <= 5; i++)
	{
		int c = fork();
		if(c == 0)
		{
			settickets(i*10);
			printf(0, "Created Child %d with PID:%d\n", i, getpid());
			for(;;){}
		}		
	}
	
	exit();
	
}