#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct ponto
{
  int x, y;
} Ponto;

typedef struct pessoa
{
  char nome[100];
  Ponto p;
} Pessoa;

typedef struct CentroM
{
  int x, y;
} CentroM;

Pessoa *alimentar(Pessoa *pessoas, int *n)
{
  pessoas = (Pessoa *)calloc(*n, sizeof(Pessoa));
  for (int i = 0; i < *n; i++)
  {
    printf("Nome: ");
    scanf("%s", pessoas[i].nome);
    pessoas[i].p.x = rand() % 50;
    pessoas[i].p.y = rand() % 50;
  }
  return pessoas;
}

CentroM centro(Pessoa *pessoas, int n)
{
  //para calcular o centro de massa, precisaria da massa
  CentroM centro;
  centro.x = 0;
  centro.y = 0;
  for (int i = 0; i < n; i++)
  {
    centro.x += pessoas[i].p.x;
    centro.y += pessoas[i].p.y;
  }
  centro.x /= n;
  centro.y /= n;

  return centro;
}

int menorT(Pessoa *pessoas, int n)
{
  int menorTangente = 0;

  int XMax = 0, XMin = 0, YMax = 0, YMin = 0;
  for (int i = 0; i < n; i++)
  {
    int XMaxAtual = 0, XMinAtual = 0, YMaxAtual = 0, YMinAtual = 0;
    if (i == 0)
    {
      XMax = pessoas[i].p.x;
      XMin = pessoas[i].p.x;
      YMax = pessoas[i].p.y;
      YMin = pessoas[i].p.y;

      XMaxAtual = pessoas[i].p.x;
      XMinAtual = pessoas[i].p.x;
      YMaxAtual = pessoas[i].p.y;
      YMinAtual = pessoas[i].p.y;
    }
    else
    {
      if (XMax < XMaxAtual)
      {
        XMax = XMaxAtual;
      }
      if (XMin > XMinAtual)
      {
        XMin = XMinAtual;
      }

      if (YMax < YMaxAtual)
      {
        YMax = YMaxAtual;
      }
      if (YMin > YMinAtual)
      {
        YMin = YMinAtual;
      }
    }
  }
  int TX = XMax - XMin;
  int TY = YMax - YMin;

  if (TX < TY)
    return TX;
  return TY;
}

float distancia(int x1, int x2, int y1, int y2)
{
  float dis = (float)sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  return dis;
}

void main()
{
  Pessoa *pessoas;
  int n = 0;
  printf("quantidade de pessoas: ");
  scanf("%d", &n);
  srand(time(NULL));
  pessoas = alimentar(pessoas, &n);

  CentroM centroMassa = centro(pessoas, n);
  printf("Centro de massa X: %d\n", centroMassa.x);
  printf("Centro de massa Y: %d\n", centroMassa.y);

  int menorTangente = menorT(pessoas, n);
  printf("Tangente: %d\n", menorTangente);

  float raio = (float) menorTangente / 2;
  printf("Raio: %.2f\n", raio);

  printf("Estao dentro do circulo:\n");
  for (int i = 0; i < n; i++)
  {
    float dist = (float) distancia(centroMassa.x, pessoas[i].p.x, centroMassa.y, pessoas[i].p.y);

    if (dist <= raio)
    {
      printf("%s\n", pessoas[i].nome);
      printf("X: %d ", pessoas[i].p.x);
      printf("Y: %d\n",pessoas[i].p.y);
    }
  }free(pessoas);
}