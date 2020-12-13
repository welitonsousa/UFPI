"""
Sem utilizar nenhuma biblioteca tais como numpy ou pandas, faça um
código em Python para calcular a média:
a. faça uma versão para que o usuário informe 10 números.
b. faça uma versão que os 10 números são gerados
automaticamente.
"""
import random

sum = 0
sum_ramdom = 0
count_terms = 10

for index in range(0, count_terms):
  sum += int(input())
  sum_ramdom += random.randrange(0, count_terms)

print('Media: ', (sum/count_terms))
print('Media de numeros aleatorios: ', (sum_ramdom/count_terms))
