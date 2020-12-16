#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()
{
  pid_t filho;
  filho = fork();
  if (filho == -1)
    printf("Erro fork() %d: %s\n", errno, strerror(errno));
  else
  {
    if (filho == 0)
      printf("PID do processo pai = %ld, PID do filho = %ld\n", (long)getppid(), (long)getpid());
  }
}
