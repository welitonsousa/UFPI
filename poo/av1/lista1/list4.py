def desconto(litros, desconto, tipo):
    if tipo == 'G':
        preco = 4.53
        desconto += 0.01
    elif tipo == 'A':
        preco = 3.45
    return ((litros * preco) - (litros * preco * desconto))

litros = float(input())
tipo = input()

if litros > 20:
    print(desconto(litros, 0.05, tipo))
else:
    print(desconto(litros, 0.03, tipo))