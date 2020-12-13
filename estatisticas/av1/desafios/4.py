"""
Sem utilizar nenhuma biblioteca tais como numpy ou pandas, faça um
código em Python para calcular os quartis:
a. faça uma versão para que o usuário informe 20 números.
b. faça uma versão que os 20 números são gerados
automaticamente
"""
import random


def midian(array):
  array.sort()
  size = len(array)
  if size % 2 == 0:
    return (array[int(size/2)] + array[int(size/2) - 1])/2
  else:
    return array[int(size/2)]

def quartis(array):
  array.sort()
  size = len(array)
  quartis = {}

  if (size) % 2 == 0:
    quartis['q1'] = midian(array[ : int(size/2)])
    quartis['q2'] = midian(array)
    quartis['q3'] = midian(array[ int(size/2): ]) 
  else:
    quartis['q1'] = midian(array[ : int(size/2)])
    quartis['q2'] = midian(array)
    quartis['q3'] = midian(array[ int(size/2) + 1: ]) 
  return quartis

userTerms = []
ramdomTerms = []
for i in range(0, 20):
  userTerms.append(int(input()))
  ramdomTerms.append(random.randrange(0, 20))

print(quartis(userTerms))
print(quartis(ramdomTerms))
