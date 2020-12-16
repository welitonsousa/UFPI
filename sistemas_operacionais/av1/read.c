#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
  int fd, n;
  char linha[10];
  char nome[] = "/home/deborah/bart_simpsons.txt";

  fd = open(nome, O_RDONLY);
  if (fd == -1)
    printf("Erro ao abrir o arquivo: %s\n", strerror(errno));

  while ((n = read(fd, linha, 1)) > 0)
    printf("%s", linha);

  close(fd);
}
