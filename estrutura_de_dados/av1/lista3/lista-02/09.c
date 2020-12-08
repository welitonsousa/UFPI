/*
Construa uma struct que represente dispositivos eletrônicos, contendo descrição e valor. Faça
outra struct que represente pessoas, contendo nome, cpf e um ponteiro para um vetor do tipo
dispositivos eletrônicos. Faça funções para criar e apagar dispositivos eletrônicos alocados
dinamicamente. Faça também funções para armazenar e deletar pessoas cuja quantidade de
dispositivos eletrônicos é passada em tempo de execução. Teste as funções criadas no método main.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Dispositivo{
  char descricao[100];
  int valor;
};
struct Pessoa{
  char nome[100];
  int cpf;
  int countDispositivos;
  struct Dispositivo *dispositivo;
};

int menu(){
  printf("1 - Cadastrar pessoa\n");
  printf("2 - Cadastrar dispositivo\n");
  printf("3 - Mostrar todas as pessoas e dispositivos\n");
  printf("4 - Deletar pessoa\n");
  printf("5 - Deletar dispositivo\n");
  printf("0 - Sair\n");
  printf("Opcao: ");
  int option;
  scanf("%d", &option);
  return option;
}

void showAllPessoas(struct Pessoa *pessoas, int size, int showDispositivos){
  int indexPessoa, indexDispositivos;
  for (indexPessoa = 0; indexPessoa < size; indexPessoa ++){
    printf("%d - %s\tCPF: %d\n",indexPessoa + 1, pessoas[indexPessoa].nome, pessoas[indexPessoa].cpf);
    if(showDispositivos == 1 && pessoas[indexPessoa].dispositivo > 0){
      for(indexDispositivos = 0; indexDispositivos < pessoas[indexPessoa].countDispositivos; indexDispositivos++){
        printf("\tDescricao: %s\n", pessoas[indexPessoa].dispositivo[indexDispositivos].descricao);
        printf("\tValor: %d\n", pessoas[indexPessoa].dispositivo[indexDispositivos].valor);
        if(indexDispositivos + 1 != pessoas[indexPessoa].countDispositivos)
          printf("\t--------------\n");
      }
    }
  }
}

struct Pessoa *addDispositivos(struct Pessoa *pessoas, int *size){
  int indexPessoa;
  if(*size > 0){
    showAllPessoas(pessoas, *size, 0);
    printf("Digite o indice da pessoa: ");
    scanf("%d", &indexPessoa);
    if(indexPessoa > 0 && indexPessoa <= *size){
      indexPessoa -= 1;
      if(pessoas[indexPessoa].countDispositivos == 0)
        pessoas[indexPessoa].dispositivo = (struct Dispositivo*) calloc(pessoas[indexPessoa].countDispositivos + 1 ,sizeof(struct Dispositivo));
      if(pessoas[indexPessoa].countDispositivos > 0)
        pessoas[indexPessoa].dispositivo = (struct Dispositivo*) realloc( pessoas[indexPessoa].dispositivo ,(pessoas[indexPessoa].countDispositivos + 1) * sizeof(struct Dispositivo));
      printf("Valor: ");
      scanf("%d", &pessoas[indexPessoa].dispositivo[pessoas[indexPessoa].countDispositivos].valor);
      printf("Descricao: ");
      scanf("%s", &pessoas[indexPessoa].dispositivo[pessoas[indexPessoa].countDispositivos].descricao);
      pessoas[indexPessoa].countDispositivos += 1; 
      printf("Dispositivo adicionado\n");
    }else{
      printf("Indice da pessoa invalido\n");
    }
  }
  return pessoas;
}

struct Pessoa *addPessoa(struct Pessoa *pessoas, int *size){
  if(*size == 0)
    pessoas = (struct Pessoa *) calloc(*size + 1, sizeof(struct Pessoa));
  else
    pessoas = (struct Pessoa *) realloc( pessoas, (*size + 1) * sizeof(struct Pessoa));
  printf("Nome: ");

  scanf("%s",pessoas[*size].nome);
  setbuf(stdin, NULL);
  printf("CPF: ");
  scanf("%d",&pessoas[*size].cpf);
  pessoas[*size].countDispositivos = 0;
  *size += 1;
  printf("Pessoa adicionada\n");
  return pessoas;
}

struct Pessoa *removePessoa(struct Pessoa *pessoas, int *size){
  int indexPessoa;
  if(*size > 0){
    showAllPessoas(pessoas, *size, 0);
    printf("Digite o indice da pessoa: ");
    scanf("%d", &indexPessoa);
    if(indexPessoa > 0 && indexPessoa <= *size){
      indexPessoa -= 1;
      pessoas = (struct Pessoa *) realloc(pessoas, (indexPessoa) * sizeof(struct Pessoa));
      *size -= 1;
      printf("Pessoa deletada\n");
    }else{
      printf("Indice da pessoa invalido\n");
    }
  }
  return pessoas;
}

struct Pessoa *removeDispositivo(struct Pessoa *pessoas, int *size){
  int indexPessoa, indexDispositivo, i;
  if(*size > 0){
    showAllPessoas(pessoas, *size, 0);
    printf("Digite o indice da pessoa: ");
    scanf("%d", &indexPessoa);
    if(indexPessoa > 0 && indexPessoa <= *size){
      indexPessoa -= 1;
      if(pessoas[indexPessoa].countDispositivos > 0){
        for(i = 0; i < pessoas[indexPessoa].countDispositivos; i++){
          printf("%d - Descricao: %s\nValor: %s\n", i + 1, pessoas[indexPessoa].dispositivo[i].descricao, pessoas[indexPessoa].dispositivo[i].descricao);
          if(i + 1 != pessoas[indexPessoa].countDispositivos){
            printf("--------------\n");
          }
        }
        printf("Digite o indice do dispositivo: ");
        scanf("%d", &indexDispositivo);
        if(indexDispositivo > 0 && indexDispositivo <= pessoas[indexPessoa].countDispositivos){
          indexDispositivo -= 1;
          pessoas[indexPessoa].countDispositivos -= 1;
          pessoas[indexPessoa].dispositivo = (struct Dispositivo *) realloc(pessoas[indexPessoa].dispositivo, (pessoas[indexPessoa].countDispositivos) * sizeof(struct Dispositivo));
          printf("Dispositivo deletado\n");
        }else{
          printf("Indice do dispositivo invalido\n");
        }
      }else{
        printf("Nenhum dispositivo cadastrado\n");
      }  
    }else{
      printf("Indice da pessoa invalido\n");
    }
  }
  return pessoas;
}

void main(){
  struct Pessoa *pessoa;
  int sizePessoa = 0;

  do{
    switch (menu()){
    case 1:
      printf("||||||||||||||||\n");
      pessoa = addPessoa(pessoa, &sizePessoa);
      printf("Enter para continuar");
      getchar();
      getchar();
      break;
    case 2:
      printf("||||||||||||||||\n");
      pessoa = addDispositivos(pessoa, &sizePessoa);
      printf("Enter para continuar");
      getchar();
      getchar();
      break;
    case 3:
      printf("||||||||||||||||\n");
      showAllPessoas(pessoa, sizePessoa, 1);
      printf("Enter para continuar");
      getchar();
      getchar();
      break;
    case 4:
      printf("||||||||||||||||\n");
      pessoa = removePessoa(pessoa, &sizePessoa);
      printf("Enter para continuar");
      getchar();
      getchar();
      break;
    case 5:
      printf("||||||||||||||||\n");
      pessoa = removeDispositivo(pessoa, &sizePessoa);
      printf("Enter para continuar");
      getchar();
      getchar();
      break;
    case 0:
      exit(0);
      break;
    }
    printf("||||||||||||||||\n");
  }while(1);
}