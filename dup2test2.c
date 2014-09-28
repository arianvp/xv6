#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int pd[2], cpid;
  char buf;

  if (pipe(pd) == -1)
  {
    printf(2, "WTF ERR");
    exit();
  }

  cpid = fork();

  if (cpid == -1)
  {
    printf(2, "WTF ERR");
    exit();
  }

  if (cpid == 0)
  {
    close(pd[1]);
    while (read(pd[0], &buf, 1) > 0)
    {
      write(1, &buf, 1);
    }
    write(1, "\n", 1);
    close(pd[0]);
    exit();
  }
  else
  {
    close(pd[0]);
    write(pd[1], (void*)argv[1], strlen(argv[1]));
    close(pd[1]);
    wait();
    exit();
  }
}