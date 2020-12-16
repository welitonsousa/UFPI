#include <pthread.h>
#include <stdio.h>

void *sum_x(void *sum_void_ptr)
{

	int *sum_ptr = (int *)sum_void_ptr;
	int i;

	for (i = 6; i <= 50; i += 2){
		*sum_ptr += i;
	}

	printf("Thread sum terminou a soma de números pares: %d\n", *sum_ptr);

	return NULL;
}

int main(){
	int sum = 0, y = 0;

	printf("soma: %d, y: %d\n", sum, y);

	pthread_t thread_x;

	if (pthread_create(&thread_x, NULL, sum_x, &sum)){
		fprintf(stderr, "Erro ao criar a thread\n");
		return 1;
	}

	while (++y < 100)
		;

	printf("Thread main terminou de incrementar y\n");

	/* Espera a segunda thread terminar de executar */
	if (pthread_join(thread_x, NULL))
	{

		fprintf(stderr, "Erro ao esperar a thread\n");
		return 2;
	}

	printf("soma+y: %d\n", sum + y);

	return 0;
}
