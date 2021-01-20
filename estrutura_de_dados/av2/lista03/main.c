#include <stdio.h>
#include <stdlib.h>

struct no{
  int valor;
  struct no *anterior, *proximo;
};
typedef struct no No;

No *add(No *lista, int valor){
  No *elemento = (No *)malloc(sizeof(No *));
  elemento->valor = valor;
  if (lista == NULL){
    lista = elemento;
    lista->proximo = elemento;
    lista->anterior = elemento;
  }
  else{
    No *aux = lista;
    if (lista->anterior->valor < valor){
      aux->anterior->proximo = elemento;
      elemento->anterior = aux->anterior;
      aux->anterior = elemento;
      elemento->proximo = aux;
    }
    else if (lista->valor > valor){
      aux->anterior->proximo = elemento;
      elemento->anterior = aux->anterior;
      aux->anterior = elemento;
      elemento->proximo = aux;
      lista = elemento;
    }
    else{
      do{
        if (aux->valor > valor){
          aux->anterior->proximo = elemento;
          elemento->anterior = aux->anterior;
          aux->anterior = elemento;
          elemento->proximo = aux;
          break;
        }
        aux = aux->proximo;
      } while (aux != lista);
    }
  }
  return lista;
}

void mostrar_lista(No *lista){
  if (lista != NULL){
    No *aux = lista;
    do{
      printf("anterior %d\n", aux->anterior->valor);
      printf("valor %d\n", aux->valor);
      printf("proximo %d\n\n", aux->proximo->valor);
      aux = aux->proximo;
    } while (aux != lista);
  }
}

No *buscar(No *lista, int valor){
  if (lista != NULL){
    No *aux = lista;
    do{
      if (valor == aux->valor) return aux;
      aux = aux->proximo;
    } while (aux != lista);
  }
  return NULL;
}

int contar_termos(No *lista){
  int cont = 0;
  if (lista != NULL){
    No *aux = lista;
    do{
      cont++;
      aux = aux->proximo;
    } while (aux != lista);
  }
  return cont;
}

No *deletar(No *lista, int valor){
  No *resultado = buscar(lista, valor);
  if (resultado != NULL){
    if (contar_termos(lista) == 1) lista = NULL;
    else{
      if (lista == resultado) lista = resultado->proximo;
      resultado->proximo->anterior = resultado->anterior;
      resultado->anterior->proximo = resultado->proximo;
    }
  }
  free(resultado);
  return lista;
}

void liberar_memoria(No *lista){
  No *aux;
  aux = lista;
  do{
    No *t;
    t = aux->proximo;
    free(aux);
    aux = t;
  } while (aux != lista);
}

No * criar_lista(){
  return NULL;
}

void main(){
  No *lista = criar_lista();
  lista = add(lista, 2);
  lista = add(lista, 1);
  lista = add(lista, 4);
  lista = add(lista, 3);
  mostrar_lista(lista);
  printf("================\n");
  No *busca = buscar(lista, 4);
  printf("anterior %d\n", busca->anterior->valor);
  printf("valor %d\n", busca->valor);
  printf("proximo %d\n", busca->proximo->valor);

  lista = deletar(lista, 3);
  printf("================\n");
  mostrar_lista(lista);
  liberar_memoria(lista);
}