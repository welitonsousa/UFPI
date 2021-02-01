#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define BUF_SIZE 3 //tamanho do buffer

typedef struct{
    int buf[BUF_SIZE];          // definindo o buffer
    size_t len;                 // controla o número de itens do buffer
    pthread_mutex_t mutex;      // variável mutex
    pthread_cond_t can_produce; // variável condicional indicando que item(s) foram removidos
    pthread_cond_t can_consume; // variável condicional indicando que item(s) foram adicionados
} buffer_t;

void *producer(void *arg){
    /*Lê os argumentos do buffer_t inicializado no main*/
    buffer_t *buffer = (buffer_t *)arg;

    /*Bloqueia o mutex para que nenhum outro thread entre na região crítica*/
    pthread_mutex_lock(&buffer->mutex);

    /* testa se o buffer está cheio */
    while (buffer->len == BUF_SIZE){
        // é bloqueado e espera por um sinal que itens foram removidos
        printf("O buffer esta cheio\n");
        pthread_cond_wait(&buffer->can_produce, &buffer->mutex);
    }

    int item = rand() % 11;
    // Se o buffer não está cheio, produz o item aleatoriamente
    printf("Produzido: %d\n", item);

    // insere item no buffer
    buffer->buf[buffer->len] = item;
    ++buffer->len; //incrementa o contador

    // sinaliza p/ consumidor despertar que um item foi produzido
    pthread_cond_signal(&buffer->can_consume);
    // desbloqueia o mutex (libera a trava)
    pthread_mutex_unlock(&buffer->mutex);

    return NULL;
}

void *consumer(void *arg)
{
    /*Lê os argumentos do buffer_t inicializado no main*/
    buffer_t *buffer = (buffer_t *)arg;
    /*Bloqueia o mutex para que nenhum outro thread entre na região crítica*/
    pthread_mutex_lock(&buffer->mutex);
    /* testa se o buffer está vazio */
    while (buffer->len == 0)
    {
        printf("O buffer esta vazio\n");
        // é bloqueado e espera por um sinal que itens foram produzidos
        pthread_cond_wait(&buffer->can_consume, &buffer->mutex);
    }

    // decrementa o contador
    --buffer->len;
    printf("Consumido: %d\n", buffer->buf[buffer->len]);

    // sinaliza p/ produtor despertar que um item foi consumido
    pthread_cond_signal(&buffer->can_produce);

    // desbloqueia o mutex (libera a trava)
    pthread_mutex_unlock(&buffer->mutex);

    return NULL;
}

void callProducer(int repetition, pthread_t *prod, buffer_t *buffer){
    for(int i = 0; i < repetition; i ++){
        pthread_create(prod, NULL, producer, (void *)buffer);
    }
}

void callConsumer(int repetition, pthread_t *cons, buffer_t *buffer){
    for(int i = 0; i < repetition; i ++){
        pthread_create(cons, NULL, consumer, (void *)buffer);
    }
}

int main(){
    srand(time(NULL));

    pthread_t prod, cons;
    // inicializa elementos do buffer_t
    buffer_t buffer = {
        .len = 0,
        .mutex = PTHREAD_MUTEX_INITIALIZER,
        .can_produce = PTHREAD_COND_INITIALIZER,
        .can_consume = PTHREAD_COND_INITIALIZER};

    int countProducer, countConsumer;

    printf("produzir: ");
    scanf("%d", &countProducer);
    
    printf("consumir: ");
    scanf("%d", &countConsumer);
    
    callProducer(countProducer, &prod, &buffer);
    callConsumer(countConsumer, &cons, &buffer);

    if (countProducer > 0) pthread_join(prod, NULL); // espera o thread produtor terminar
    if (countConsumer > 0) pthread_join(cons, NULL); // espera o thread consumidor terminar

    printf("O programa encerrou\n");
    return 0;

}