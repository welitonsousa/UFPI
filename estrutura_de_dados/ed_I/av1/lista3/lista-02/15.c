#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fone{
  char codigo[3];
  char area[3];
  char numero[4];
};

void mostrarFone(void *string, int size){
  int i;
  char stringAux [10];
  strcpy(stringAux, string);
  for(i=0; i < size; i++){
    if(i == 0)
      printf("(");
    else if(i == 3)
      printf(") ");
    else if(i == 6)
      printf("-");
    
    printf("%c", stringAux[i]);
  }
  printf("\n");
}
void main(){
  struct fone f = {{"123"},{"456"},{"7849"}};
  int size = 10;
  char s[] ={"1234567849"};
  mostrarFone(&f, size);
  mostrarFone(s, size);
}