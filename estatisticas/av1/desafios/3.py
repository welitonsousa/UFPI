"""
Sem utilizar nenhuma biblioteca tais como numpy ou pandas, faça um
código em Python para calcular a mediana:
a. faça uma versão para que o usuário informe 10 números.
b. faça uma versão que os 10 números são gerados
automaticamente
"""
import random

count_terms = 10
user_terms = []
terms_random = []

for i in range(0, count_terms):
  user_terms.append(int(input()))
  terms_random.append(random.randrange(0, count_terms))

terms_random.sort()
print(terms_random)

if len(terms_random) %2 == 1:
  print("Mediana aleatorias: ",terms_random[int(len(terms_random) / 2)])
else:
  a = terms_random[int((len(terms_random) / 2) - 1)]
  b = terms_random[int(len(terms_random) / 2)]
  print("Mediana aleatorias: ",( a + b ) / 2)

user_terms.sort()
print(user_terms)

if len(user_terms) %2 == 1:
  print("Mediana usuario: ",user_terms[int(len(user_terms) / 2)])
else:
  a = user_terms[int((len(user_terms) / 2) - 1)]
  b = user_terms[int(len(user_terms) / 2)]
  print("Mediana usuario: ",( a + b ) / 2)
