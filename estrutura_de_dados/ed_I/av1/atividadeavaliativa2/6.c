#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct ponto ponto;
typedef struct grupo Grupo;

struct ponto{
  int x, y, valor;
};

struct grupo{
  ponto semente;
  ponto *elementos;
  int rotulo; //valor que identifica os pontos pertencentes ao grupo
  int qtdelementos;
};

void main(){
  int **mat, *elementos;
  int l, count = 0, tam;

  Grupo *grupo;

  printf("Tamanho da matriz: ");
  scanf("%d", &tam);

  int elementosSemGrupo = tam * tam;

  srand(time(NULL));
  mat = (int **)calloc(tam, sizeof(int));

  for (int i = 0; i < tam; i++){
    mat[i] = (int *)calloc(tam, sizeof(int));
    for (int j = 0; j < tam; j++){
      mat[i][j] = rand() % 250;
      printf("%03d ", mat[i][j]);
    }
    printf("\n");
  }

  while (elementosSemGrupo != 0){
    printf("Raio: ");
    scanf("%d", &l);

    printf("X Y: ");
    int a, b;
    scanf("%d %d", &a, &b);

    if (a >= 0 && b >= 0 && a < tam && b < tam && mat[a][b] < 256){
      if (count == 0){
        grupo = (Grupo *)calloc(1, sizeof(Grupo));
      }
      else{
        grupo = (Grupo *)realloc(grupo, (count + 1) * sizeof(Grupo));
      }
      grupo[count].qtdelementos = 0;
      grupo[count].semente.x = a;
      grupo[count].semente.y = b;
      grupo[count].semente.valor = mat[a][b];
      grupo[count].rotulo = 256 + count;
      if (grupo[count].qtdelementos == 0)
        grupo[count].elementos = (ponto *)calloc(1, sizeof(ponto));
      grupo[count].elementos[grupo[count].qtdelementos].valor = mat[a][b];
      grupo[count].elementos[grupo[count].qtdelementos].x = a;
      grupo[count].elementos[grupo[count].qtdelementos].y = b;
      mat[a][b] = grupo[count].rotulo;

      grupo[count].qtdelementos++;
      for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
          int dis = (int)sqrt(pow(a - i, 2) + pow(b - j, 2));
          if (dis <= l && mat[i][j] < 256 && grupo[count].qtdelementos > 0){
            grupo[count].elementos = (ponto *)realloc(grupo[count].elementos, ((grupo[count].qtdelementos + 1) * sizeof(ponto)));
            grupo[count].elementos[grupo[count].qtdelementos].valor = mat[i][j];
            grupo[count].elementos[grupo[count].qtdelementos].x = i;
            grupo[count].elementos[grupo[count].qtdelementos].y = j;
            grupo[count].qtdelementos += 1;
            mat[i][j] = grupo[count].rotulo;
          }
        }
      }
      elementosSemGrupo -= grupo[count].qtdelementos;
      count+=1;
    }
    else
      printf("Posicao invalida\n");
  }

  for (int i = 0; i < count; i++){
    printf("Grupo: %d\n", grupo[i].semente.valor);
    for (int j = 0; j < grupo[i].qtdelementos; j++){
      printf("%d ", grupo[i].elementos[j].valor);
    }
    printf("\n");
  }

  printf("\nmatriz\n");
  for (int i = 0; i < tam; i++){
    for (int j = 0; j < tam; j++){
      printf("%d ",mat[i][j]);
    }
    printf("\n");
  }
}