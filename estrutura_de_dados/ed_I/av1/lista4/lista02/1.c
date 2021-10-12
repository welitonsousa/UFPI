// Fazer um registro (struct) para um cliente, com: nome, RG, CPF, idade, endereço
// residencial, endereço de trabalho, telefone celular, telefone fixo. Na função principal
// solicite ao usuário que preencha essa estrutura, depois imprima os dados que foram
// cadastrados.

#include <stdio.h>

struct Client{
  char name[100];
  int rg;
  int cpf;
  int age;
  char residentialAddress[200];
  char workAddress[200];
  int smartphone;
  int telephone;
};
typedef struct Client Client;

void main(){
  Client client;
  printf("Preencha todos os dados do cliente\nNome: ");
  scanf("%s", client.name);
  printf("RG: ");
  scanf("%d", &client.rg);
  printf("CPF: ");
  scanf("%d", &client.cpf);
  printf("Idade: ");
  scanf("%d", &client.age);
  printf("Endereco residencial: ");
  setbuf(stdin, NULL);
  scanf("%s", client.residentialAddress);
  printf("Endereco de trabalho: ");
  setbuf(stdin, NULL);
  scanf("%s", client.workAddress);
  printf("Celular: ");
  scanf("%d", &client.smartphone);
  printf("Telefone: ");
  scanf("%d", &client.telephone);

  printf("\n");
  printf("Nome: %s\n", client.name);
  printf("Rg: %d\n", client.rg);
  printf("CPF: %d\n", client.cpf);
  printf("Idade: %d\n", client.age);
  printf("Endereco residencial: %s\n", client.residentialAddress);
  printf("Endereco comercial: %s\n", client.workAddress);
  printf("Telefone celular: %d\n", client.smartphone);
  printf("Telefone fixo: %d\n", client.telephone);
}
