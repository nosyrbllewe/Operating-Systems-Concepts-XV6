#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  printf(1, "Now calling getpid(). PID: %d\n", getpid());
  exit();
}
