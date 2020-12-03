def tab (a,b):
    if a <= b:
        print(val, ' X ', a, ' = ', val * a)
        return tab(a + 1, b)

val = int(input('Montar taboada de: '))
init = int(input('Começa por: '))
end = int(input('Termina em: '))

tab(init, end)