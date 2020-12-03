agenda = []

for i in range(0, 10):
    pessoa = {
        'nome': input('Nome: '),
        'endereco': input('Endereco: '),
        'cep': input('cep: '),
        'bairro': input('Bairro: '),
        'telefone': input('Telefone: '),
    }
    agenda.append(pessoa)

agenda.reverse()
for pessoa in agenda:
    print(pessoa)