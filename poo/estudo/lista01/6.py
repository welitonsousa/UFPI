numero_rodadas = int(input())
palavras_criticas = {}
reacao = ''

for i in range(0, numero_rodadas):
    a = input().split(' ')
    palavras_criticas[a[0]] = a[1]

frase = input().split(' ')
for palvra in frase:
    try:
        reacao += palavras_criticas[palvra] + ' '
    except:
        pass

print(reacao if reacao else 'Tudo bem!')
