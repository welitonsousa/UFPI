#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void main(){
    int m = 10, n = 15;
    int userInput;
    int matriz[m][n];
    double higherAverage = 0, lowerAverage = 0, detour = 0;
    int termsHight = 0, termsLower = 0;
   
    srand(time(NULL));
    for(int index = 0; index < m; index++){
        for(int indexTwo = 0; indexTwo < n; indexTwo++){
            matriz[index][indexTwo] = (rand() % 500) + 1;
        }
    }

    do{
        scanf("%d", &userInput);
    }while(userInput > 500 || userInput < 1);
    
    for(int index = 0; index < m; index++){
        for(int indexTwo = 0; indexTwo < n; indexTwo++){
            if(matriz[index][indexTwo] > userInput){
                higherAverage += matriz[index][indexTwo];
                termsHight ++;
            }else if (matriz[index][indexTwo] < userInput){
                lowerAverage += matriz[index][indexTwo];
                termsLower ++;
            }   
        }
    }

    higherAverage = higherAverage / termsHight;
    lowerAverage = higherAverage / termsHight;

    for(int index = 0; index < m; index++){
        for(int indexTwo = 0; indexTwo < n; indexTwo++){
            if(matriz[index][indexTwo] > userInput){
                detour += pow(matriz[index][indexTwo] - higherAverage, 2);
            }
        }
    }
    detour = sqrt(detour/higherAverage);
    printf("Media maior: %.2f\nMedia menor: %.2f\nDesvio padrao: %.2f", higherAverage, lowerAverage, detour);
}
