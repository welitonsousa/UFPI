import random

while True:
    numberSorted = random.randrange(1, 10)
    for i in range(0, 10):
        displayInfo = str(i+1) +'ª Tentativa: '
        userInput = int(input(displayInfo))
        if userInput == numberSorted:
            print('Você acertou o numero')
            break
    print('Deseja jogar novamente? \n 1 - SIM \n 2 - NAO \n')
    if int(input()) == 2:
        break