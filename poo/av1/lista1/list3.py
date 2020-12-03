def imposto (imp):
    return round(salario * imp, 1)

salarioHora = float(input())
horas = int(input())
salario = salarioHora * horas

ir = imposto(0.11)
inss = imposto(0.08)
sindicato = imposto(0.05)
salarioLiquido = salario - (ir + inss + sindicato)

print('Salario bruto: ', salario)
print('IR: ', ir)
print('INSS: ', inss)
print('Sindicato: ', sindicato)
print('salario Liquido: ', salarioLiquido)