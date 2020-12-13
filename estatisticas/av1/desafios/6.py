"""
Sem utilizar nenhuma biblioteca tais como numpy ou pandas, faça um
código em Python para calcular a Amplitude (nem usar built-in functions como
max e min das listas):
a. faça uma versão para que o usuário informe 10 números.
b. faça uma versão que os 10 números são gerados
automaticamente.
c. Faça uma versão usando as built-in functions (max e min).
"""

import random


#usando logica 
def amplitude(array, string):
  array.sort()
  max_variable = array[0]
  min_variable = array[len(array) - 1]
  print('Usando logica')
  print('Amplitude ', string)
  print((max_variable + min_variable) / 2)

# built-in functions
def amplitude_build(array, string):
  array.sort()
  max_variable = max(array)
  min_variable = min(array)
  print('Usando max e min')
  print('Amplitude ', string)
  print((max_variable + min_variable) / 2)

userTerms = []
randomTerms = []
for i in range(0, 20):
  randomTerms.append(random.randrange(0, 20))
  userTerms.append(int(input()))

amplitude(userTerms, 'usuario')
amplitude(randomTerms, 'aleatoria')

amplitude_build(userTerms, 'usuario')
amplitude_build(randomTerms, 'aleatoria')
