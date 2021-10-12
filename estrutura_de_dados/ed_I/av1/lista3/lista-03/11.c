// Considere a estrutura de dados Hidrocarboneto formada pelos campos C e H
// ambos inteiros correspondentes à quantidade de carbonos e hidrogênios de
// determinado composto. Crie uma função que, após alocar dinamicamente uma
// variável do tipo Hidrocarboneto, receba do usuário a quantidade de carbonos e
// hidrogênios possuída por determinado elemento e imprima a massa molecular
// do composto. Considere que C (carbono) = 12 e H (hidrogênio) = 1.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Hidrocarboneto{
  int carbono;
  int hidrogenio;
};

struct Hidrocarboneto *allocArray(int size){
  struct Hidrocarboneto *array;
  array = (struct Hidrocarboneto *)calloc(size, sizeof(struct Hidrocarboneto));
  return array;
}

void main(){
  int sizeArray = 1;
  struct Hidrocarboneto *compostoQuimico = allocArray(sizeArray);
  scanf("%d %d", &compostoQuimico[0].carbono, &compostoQuimico[0].hidrogenio);

  int massamolecular = (12 * compostoQuimico[0].carbono) + (1 * compostoQuimico[0].hidrogenio);
  printf("Massa molecular: %d", massamolecular);
}
