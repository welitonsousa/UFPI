"""
Sem utilizar nenhuma biblioteca tais como numpy ou pandas, faça um
código em Python para calcular os decis:
a. faça uma versão para que o usuário informe 20 números.
b. faça uma versão que os 20 números são gerados
automaticamente
"""
import random


def decis(array):
  decis = []
  array.sort()
  print(array)
  for index in range(1, 10):
    decis.append(array[int((index * len(array))/ 10)])
  return decis

userTerms = []
randomTerms = []
for i in range(0, 20):
  userTerms.append(int(input()))
  randomTerms.append(random.randrange(0, 20))

print('Decis do usuario')
print(decis(userTerms))

print('Decis aleatoricos')
print(decis(randomTerms))
