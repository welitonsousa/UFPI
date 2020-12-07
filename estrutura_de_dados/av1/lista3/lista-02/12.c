/*
Altere a questão anterior para que possa ajudar não o professor, mas os monitores no
acompanhamento dos exercícios propostos. Seu programa não precisa armazenar notas, mas a
quantidade e quais questões os alunos tiveram dificuldade num dado exercício. Associe, da maneira
que preferir, os exercícios e questões aos alunos e escreva funções para recuperar: Quais questões
um dado aluno teve dificuldade; E/Ou Quais alunos dada questão apresentou dificuldade;
*/

#include "12-funcoes.h"

void main(){
  struct Aluno *alunos;
  int size = 0;

  while (1){
    alunos = menu(alunos, &size);
  }
}