#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define tam 225

typedef struct ponto ponto;
typedef struct grupo Grupo;

struct ponto
{
  int x, y, valor;
};

struct grupo
{
  ponto semente;
  ponto *elementos;
  int rotulo; //valor que identifica os pontos pertencentes ao grupo
  int qtdelementos;
};

int **lerMat()
{
  FILE *file;
  int **mat;
  mat = (int **)calloc(tam, sizeof(int));
  for (int i = 0; i < tam; i++)
  {
    mat[i] = (int *)calloc(tam, sizeof(int));
  }

  file = fopen("matriz.txt", "r");
  if (file == NULL)
  {
    exit(0);
  }
  else
  {
    for (int i = 0; i < tam; i++)
    {
      for (int j = 0; j < tam; j++)
      {
        fscanf(file, "%d ", &mat[i][j]);
      }
    }
    fclose(file);
  }
  return mat;
}

void main()
{
  int **mat, *elementos;
  int l = 2, count = 0;

  Grupo *grupo;

  int elementosSemGrupo = tam * tam;
  mat = lerMat();

  int entradasX[] = {50, 38, 129, 104, 195, 168, 15};
  int entradasY[] = {50, 101, 60, 163, 132, 177, 15};

  for (int w = 0; w < 7; w++){
    int a = entradasX[count];
    int b = entradasY[count];

    if (count == 0){
      grupo = (Grupo *)calloc(1, sizeof(Grupo));
      count = 0;
    }
    else
    {
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
    count += 1;
    printf("\n%d\n", count);
  }

  for (int i = 0; i < count; i++){
    printf("Grupo: %d\n", grupo[i].rotulo);
    for (int j = 0; j < grupo[i].qtdelementos; j++){
      printf("[%d][%d] = %d ",grupo[i].elementos[j].x, grupo[i].elementos[j].y, grupo[i].elementos[j].valor);
      printf("\n");
    }
  }
  printf("\nmatriz\n");
  for (int i = 0; i < count; i++){
    for (int j = 0; j < grupo[i].qtdelementos; j++){
      printf("%d ", grupo[i].elementos[j].valor);
    }
    printf("\n");
  }
}