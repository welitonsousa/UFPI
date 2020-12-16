numero_rodadas = int(input())
rodadas = []
for i in range(0, numero_rodadas):
    rodadas.append(input().split(' '))

count = ['', 1]
for index in range(0, len(rodadas)):
    count = rodadas[int(count[1]) - 1]

print(rodadas[int(count[1]) - 1][0])
