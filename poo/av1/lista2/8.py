import random
def createArray():
    array = []
    for i in range(0,13):
        array.append(random.randrange(1,4))
    return array

def verifyArray(bet):
    betAcept = 0
    for i in range(0, len(numbersSorted)):
        if numbersSorted[i] == bet[i]:
            betAcept += 1
    return betAcept

numbersSorted = createArray()

betOne = verifyArray(createArray())
betTwo = verifyArray(createArray())
betTree = verifyArray(createArray())

print('1º Apostador: ', betOne, 'Acertos', ' Ganhador' if betOne == 13 else '' )
print('2º Apostador: ', betTwo, 'Acertos', ' Ganhador' if betTwo == 13 else '' )
print('3º Apostador: ', betTree, 'Acertos', ' Ganhador' if betTree == 13 else '' )