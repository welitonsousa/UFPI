#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void main(){
    int m = 10, n = 15;
    int matriz[m][n];
    int notShow[250];

    srand(time(NULL));
    for(int index = 0; index < m; index++){
        for(int indexTwo = 0; indexTwo < n; indexTwo++){
            matriz[index][indexTwo] = (rand() % 250) + 1;
        }
    }

    int notShowIndex = 0;
    for(int flag = 1; flag <= 250; flag ++){
        int count = 0;
        for(int index = 0; index < m; index++){
            for(int indexTwo = 0; indexTwo < n; indexTwo++){
                if(matriz[index][indexTwo] == flag){
                    matriz[index][indexTwo] == -1;
                    count++;
                }
            }
        };
        if(count > 1){
            printf("%d repetiu %d vezes\n",flag, count);
        }else if(count == 0){
            notShow[notShowIndex] = flag;
            notShowIndex++;
        }
    }
    printf("\nNao apareceram\n");
    for(int index = 0; notShow[index] != '\0'; index ++){
        printf("%d \n", notShow[index]);
        //if(index % 10 == 0) printf("\n");
    }
}
