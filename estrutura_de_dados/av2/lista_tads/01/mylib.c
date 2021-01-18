#include "mylib.h"

void menu(int *op){
    printf(" 1- Somar\n 2-Subtrair\n 3-Dividir\n 4-Multiplicar\n 5-Sair\n");
    scanf("%d", op);
}

void numeros(float *p_num1, float *p_num2){
    scanf("%f %f", p_num1, p_num2);
}
void soma(float num1, float num2, float *p_result){
    *p_result = num1 + num2;
}
void subtrair(float num1, float num2, float* p_result){
    *p_result = num1 - num2;
}
void dividir(float num1, float num2, float* p_result){
    *p_result = num1 / num2;
}
void multiplicar(float num1, float num2, float* p_result){
    *p_result = num1 * num2;
}
