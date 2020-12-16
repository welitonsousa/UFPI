#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int main()
{
  if (mkdir("so_system_calls1", S_IROTH | S_IWUSR | S_IXUSR) != 0)
    printf("Erro na chamada mkdir: %s\n", strerror(errno));
  system("ls -l");
}
