entradas = int(input())
atividades = []

for i in range(0, entradas):
    ati = input()
    horarios = ati[len(ati) - 11: ].split(' ')
    horario_inicio, horario_fim = horarios[0], horarios[1]
    nome_atividade = ati[0: len(ati) - len(horario_fim + horario_inicio) - 2]

    atividades.append({
        'nome': nome_atividade,
        'inicio': horario_inicio,
        'fim': horario_fim,
    })

atividades_diarias = []
for index in range(0, len(atividades)):
    if index == 0:
        atividades_diarias.append(atividades[index])

    elif atividades[index]['inicio'] > atividades_diarias[len(atividades_diarias) -1 ]['fim']:
        atividades_diarias.append(atividades[index])

print(len(atividades_diarias))
for atividade in atividades_diarias:
    print(atividade['nome'])   