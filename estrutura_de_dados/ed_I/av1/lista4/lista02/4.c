// Escreva uma estrutura chamada pessoa que deve conter cinco atributos nome, idade,
// peso, altura e pessoa.imc.
// Faça uma função que deve calcular o Índice de Massa Corporal (pessoa.imc) de uma pessoa,
// tendo como parâmetros o peso e a altura, retornando o resultado. A formula para o
// cálculo é a seguinte: pessoa.imc = peso * altura2.
// Na função principal crie um vetor de ponteiros para estrutura pessoa, preencha esse
// vetor, sendo que o pessoa.imc deve ser preenchido automaticamente com a chamada da função
// que realiza seu cálculo. De acordo com a tabela de classificação, informe os resultados
// em porcentagem para cada categoria

#include <stdio.h>

struct Person{
  char name[100];
  int age;
  float weight;
  float height;
  float imc;
};typedef struct Person Person;

void main(){
  Person person;

  printf("Nome: ");
  scanf("%s", person.name);
  printf("Idade: ");
  scanf("%d", &person.age);
  printf("Peso: ");
  scanf("%f", &person.weight);
  printf("Altura: ");
  scanf("%f", &person.height);

  person.imc = person.weight / (person.height * person.height);

  if (person.imc < 18.5)
    printf("Abaixo do peso\n");
  else if (person.imc > 18.5 && person.imc < 24.9)
    printf("Peso normal\n");
  else if (person.imc > 25 && person.imc < 29.9)
    printf("Levemente acima do peso\n");
  else if (person.imc > 30 && person.imc < 34.9)
    printf("Obeso\n");
  else if (person.imc > 35 && person.imc < 39.9)
    printf("Obesidade Severa\n");
  else if (person.imc > 40)
    printf("Obesidade Morbida\n");
}
