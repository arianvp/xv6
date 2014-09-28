#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  char *grep_args[] = {"grep", "xv6", (void*)0};
  int in, out;
  in = open ("README", O_RDONLY);
  out = open ("out", O_WRONLY);

  dup2(in, 0);
  dup2(out, 0);

  close(in);
  close(out);
  exec(grep_args[0], grep_args);
  return 0;
}