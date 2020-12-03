corredores = {}
menorTime = 0
quantidadeCorredores = 2
quantidadeVoltas = 3
vencedor = ''

print('Cadastre os corredores\n')
menorTimeTotal = 0
for i in range(0, quantidadeCorredores):
    name = input('Corredor N' + str(i + 1)+ ': ') 
    voltas = []
    timeTotal = 0
    for indexVolta in range(0, quantidadeVoltas):

        time = int(input('Volta N' + str(indexVolta + 1) + ': '))
        voltas.append(time)
        timeTotal += time

        if i  == 0 and indexVolta == 0:
            menorTime = time
        if time < menorTime:
            menorTime = time
    if i == 0:
        menorTimeTotal = timeTotal
    if timeTotal <= menorTimeTotal:
        menorTimeTotal = timeTotal
        vencedor = name

    corredores[name] = voltas

print('\nVencedor: ', vencedor)
print('Melhor volta: ', menorTime)
