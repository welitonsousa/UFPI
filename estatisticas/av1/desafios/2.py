"""
Sem utilizar nenhuma biblioteca tais como numpy ou pandas, faça um
código em Python para calcular a moda:
a. faça uma versão para que o usuário informe 10 números.
b. faça uma versão que os 10 números são gerados
automaticamente.
"""
import random

count_terms = 10

user_terms = []
repetitions = []

terms_random = []
repetitions_random = []

for index in range(0, count_terms):
  current_term = int(input())
  current_random = random.randrange(0, count_terms)
  sum_term = 0
  for i in range(0, len(user_terms)):
    if user_terms[i] == current_term:
      sum_term += 1
      repetitions[i] += 1
  if sum_term == 0:
    user_terms.append(current_term)
    repetitions.append(1)

  sum_term = 0
  for i in range(0, len(terms_random)):
    if terms_random[i] == current_random:
      sum_term += 1
      repetitions_random[i] += 1
  if sum_term == 0:
    terms_random.append(current_random)
    repetitions_random.append(1)

print("Moda do usuario: ")
max_repetition = max(repetitions)
for i in range(0, len(repetitions)):
  if repetitions[i] == max_repetition:
    print(user_terms[i], " Apareceu ", repetitions[i], "vezes")

print("\nModa aleatoria: ")
max_repetition = max(repetitions_random)
for i in range(0, len(repetitions_random)):
  if repetitions_random[i] == max_repetition:
    print(terms_random[i], " Apareceu ", repetitions_random[i]," vezes")
