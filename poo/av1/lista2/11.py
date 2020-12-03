alunos = {}

for i in range(0, 2):
    name = input('Nome do aluno: ')
    alunos[name] = (float(input('Nota 1: ')) + float(input('Nota 2: '))) / 2

print(alunos.get(input('Buscar aluno: '), 'Anuno nao encontrado'))
