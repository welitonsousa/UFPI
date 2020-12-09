peso = float(input())
print(peso)
if peso > 50:
    excesso = round(peso - 50, 1)
    multa = round(excesso * 4, 1)
    print('peso:', peso, '\nExcesso:', excesso,'\nMulta:', multa)