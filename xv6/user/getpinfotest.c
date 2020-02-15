#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

#define NProc 64
int
main(int argc, char *argv[])
{
	struct pstat p;
	int i;
	for(i = 0; i < NProc; i++)
	{
		p.inuse[i] = 0;
		p.tickets[i] = 0;
		p.pid[i] = -1;
		p.ticks[i] = 0;
	}
	int info = getpinfo(&p);
	if(info == 0)
		for(i = 0; i < NProc; i++)
			printf(2, "PID: %d\tinuse: %d\ttickets: %d\tticks: %d\n", p.pid[i], p.inuse[i], p.tickets[i], p.ticks[i]);
	else
		printf(0,"Failed to get process info\n");
	exit();
}