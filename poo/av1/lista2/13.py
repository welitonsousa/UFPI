agenda = []
def displayMenu():
    print('1 - Novo contato')
    print('2 - Novo telefone')
    print('3 - Excluir telefone')
    print('4 - Excluir contato')
    print('5 - Listar contatos')
    print('6 - Consultar telefone')

def addContact():
    nome = input('Nome: ')
    telefones = []
    print('0 - Salvar')
    while True:
        telefone = int(input('Telefone: '))
        if telefone == 0:
            agenda.append({
                'nome': nome,
                'telefones': telefones,
            })
            print('Contato salvo')
            break
        else:
            telefones.append(telefone)

def listAllContacts():
    positionContact = 0
    for contact in agenda:
        positionContact += 1
        print( positionContact,' - ', contact['nome'])

def deletContact():
    listAllContacts()
    indexContact = int(input('\nDigite o index do contato: ')) - 1
    if indexContact >= 0 and indexContact <= len(agenda) - 1:
        agenda.pop(indexContact)
        print('Contato deletado')

def listAllTelephone():
    listAllContacts()
    indexContact = int(input('\nDigite o index do contato: ')) - 1
    if indexContact >= 0 and indexContact < len(agenda):
        print('Nome: ', agenda[indexContact]['nome'])
        index = 0
        for telefone in agenda[indexContact]['telefones']:
            index += 1
            print('Telefone ',index,': ', telefone)
    return indexContact
        
def addNewTelephone():
    listAllContacts()
    indexContact = int(input('\nDigite o index do contato: ')) - 1
    if indexContact >= 0 and indexContact < len(agenda):
        print('Nome: ', agenda[indexContact]['nome'])
        print('0 - Salvar')
        while True:
            telefone = int(input('Telefone: '))
            if telefone == 0:
                print('Contato salvo')
                break
            else:
                agenda[indexContact]['telefones'].append(telefone)

def deletTelephone():
    indexContact = listAllTelephone()
    if indexContact >= 0 and indexContact<len(agenda):
        indexTelephone  = int(input('\nDigite o index do telefone: ')) - 1
        if indexTelephone >= 0 and indexTelephone <= len(agenda[indexContact]['telefones']) - 1:
            agenda[indexContact]['telefones'].pop(indexTelephone)
            print('Telefone deletado')

def clean():
    print('')
    print('---------------------')
    print('')

clean()
while True:
    displayMenu()
    userInput = int(input('\nDigite uma opcao: '))
    if userInput == 1:
        clean()
        addContact()
        clean()
    if userInput == 2:
        clean()
        addNewTelephone()
        clean()
    elif userInput == 3:
        clean()
        deletTelephone()
        clean()
    elif userInput == 4:
        clean()
        deletContact()
        clean()
    elif userInput == 5:
        clean()
        listAllContacts()
        clean()
    elif userInput == 6:
        clean()
        listAllTelephone()
        clean()
    elif userInput < 0:
        break
    else:
        clean()
        print('Opcao invalida')
        clean()