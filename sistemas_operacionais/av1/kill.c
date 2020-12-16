#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <signal.h>

int main()
{
  pid_t pid = 11544;
  int sig = 9;
  int killed = kill(pid, sig);
  if (killed == -1)
    printf("Erro kill() %d: %s\n", errno, strerror(errno));
  if (killed == 0)
    printf("Processo %d finalizado!", pid);
}
