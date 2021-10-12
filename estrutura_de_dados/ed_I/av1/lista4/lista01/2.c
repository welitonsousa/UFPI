/*
Fazer um programa de ‘dialogo de login’ onde seja possível cadastrar no
máximo 10 nomes de usuário e suas respectivas senhas (nomes de usuário
repetidos devem ser descartados). No diálogo de login, o programa deve
testar se o usuário fornecido existe e se a sua senha confere
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Users{
  char name[20];
  char password[20];
};
typedef struct Users Users;

void main(){
  int i = 0, j = 0, countUsers = 2;
  Users *users = calloc(countUsers, sizeof(Users));
  for(i = 0; i < countUsers; i++){
    printf("Usuario N%d: ", i + 1);
    scanf("%s", users[i].name);
    for(j = 0; j < i; j++){
      if(!strcmp(users[i].name, users[j].name))
        break;
    }
    if (j == i){
      printf("Senha: ");
      scanf("%s", users[i].password);
    }else{
      i -= 1; 
      printf("Usuario invalido\n");
    }
  }

  printf("Login\n\n");
  while (1){
    char userName[20], userPassword[20];
    printf("Usuario: ");
    scanf("%s",userName);
    printf("Senha: ");
    scanf("%s",userPassword);
    for(i = 0; i < countUsers; i++){
      if( !strcmp(users[i].name, userName) && !strcmp(users[i].password, userPassword)){
        printf("Sistema conectado");
        exit(0);
      }
    }
    printf("Credenciais invalidas\n");
  }
  
}
