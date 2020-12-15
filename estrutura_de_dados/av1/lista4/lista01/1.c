/*
Faça um programa em C que leia os dados de cinco pessoas, 
como o nome, a idade e o sexo e ao final imprima a média das 
idades e quantas pessoas têm idade maior que a média.
*/

#include <stdio.h>

struct Person{
  char name[20];
  int age;
  char sex;
};
typedef struct Person Person;

void main(){
  int i, count = 5, highestAverage = 0;
  float average = 0;
  Person person[5];

  for(i = 0; i < count; i++){
    printf("Pessoa N %d\n", i + 1);
    printf("Nome: ");
    scanf("%s", person[i].name);
    
    printf("Idade: ");
    scanf("%d", &person[i].age);
    
    printf("Sexo: ");
    setbuf(stdin, NULL);
    scanf("%c",&person[i].sex);
    
    printf("\n");
    average += (float) person[i].age;
  }
  average = average / count;
 
  for(i = 0; i < 5; i++){
    if (person[i].age > average)
      highestAverage += 1;
  }
  printf("Media: %.2f", average);
  printf("Idades maiores que a media: %d", highestAverage);
}