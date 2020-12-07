#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno{
  char nome[100];
  char dificuldades[100];
};

void showAllStudants(struct Aluno *listAlunos, int size){
  int i, j;
  if(size > 0){
    for(i = 0; i < size; i++){
      printf("%d - ",i+1);
      for(j = 0; listAlunos[i].nome[j]!= '\0'; j++){
        printf("%c", listAlunos[i].nome[j]);
      }
      printf("\n");
    }
  }else{
    printf("Nenhum aluno cadastrado\n");
  }
}

void showStudantsWhitDifficult(struct Aluno *alunos, int *size){
  int i, j;
  if(*size > 0){
    for(i = 0; i < *size; i++){
      if(alunos[i].dificuldades[0] != '-'){
        printf("%d - ",i+1);
        for(j = 0; alunos[i].nome[j]!= '\0' && alunos[i].dificuldades[0] != '-'; j++){
          printf("%c", alunos[i].nome[j]);
        }
        printf("\tDificuldades: ");
        for(j = 0; j < 100 && alunos[i].dificuldades[j] != '-'; j++){
          printf("%c", alunos[i].dificuldades[j]);
          if(alunos[i].dificuldades[j + 1] != '-')
            printf(", ");
        }
        printf("\n");
      }
      
    }
  }
}

struct Aluno * addStudant(struct Aluno *list, int *size){
  *size += 1;
  int i;
  if(*size == 1)
    list = (struct Aluno *)malloc(*size * sizeof(struct Aluno));
  else
    list = (struct Aluno *)realloc(list, *size * sizeof(struct Aluno));
  
  printf("Nome: ");
  scanf("%s", list[*size - 1].nome);
  setbuf(stdin, NULL);
  for(i = 0; i < 100; i++){
    list[*size - 1].dificuldades[i] = '-';
  }
  return list;
}

struct Aluno * addDifficulty(struct Aluno *listAlunos, int *size){
  int i;
  showAllStudants(listAlunos, *size);

  printf("\nSelecione a posicao do aluno: ");
  int position = -1;
  scanf("%d", &position);

  if(position > 0 && position <= *size){
    position -= 1;
    printf("Digite o numeor de dificuldades: ");
    int countDifficulty;
    scanf("%d", &countDifficulty);
    getchar();
    for (i = 0; i < countDifficulty; i++){
      printf("N da questao: ");
      char question;
      scanf("%c", &question);
      setbuf(stdin, NULL);
      listAlunos[position].dificuldades[i] = question;
    }
    
  }else{
    printf("Esta posicao nao existe\n");
  }
  return listAlunos;
}


struct Aluno * menu(struct Aluno *alunos, int *size){
  int opcao = 0;
  printf("MENU\n");
  printf("1 - Cadastrar aluno\n");
  printf("2 - Atribuir nova dificuldade\n");
  printf("3 - Imprimir alunos com dificuldade\n");;
  printf("4 - Imprimir Alunos\n");
  printf("Valor: ");
  
  scanf("%d", &opcao);
  printf("||||||||||||||||||||||\n");
  switch (opcao){
  case 1:
    alunos = addStudant(alunos, size);
    break;
  case 2:
    alunos = addDifficulty(alunos, size);
    break;
  case 3:
    showStudantsWhitDifficult(alunos, size);
    break;
  case 4:
    showAllStudants(alunos, *size);
    break;
  default:
    printf("\nFim");
    exit(0);
    break;
  }
  printf("||||||||||||||||||||||\n");
  return alunos;
}
