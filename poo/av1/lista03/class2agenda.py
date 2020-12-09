"""
Crie uma classe Agenda que pode armazenar 10 pessoas e que seja capaz de realizar as seguintes operações:
a. armazenaPessoa(nome, idade, altura);
b. removePessoa(nome);
c. buscaPessoa(nome); // informa em que posição da agenda está a pessoa
d. imprimeAgenda(); // imprime os dados de todas as pessoas da agenda
e. imprimePessoa(index); // imprime os dados da pessoa que está na posição “i” da agenda.
"""
from class1pessoa import Person


class Persons:
    _schedule = []

    def store_person(self, name, birth, height):
        if len(self.__class__._schedule) < 10:
            self.__class__._schedule.append(Person(name, birth, height))

    def search(self, name):
        for i in range(0, len(self.__class__._schedule)):
            if self.__class__._schedule[i].name == name:
                return i

    def remove_person(self, name):
        self.__class__._schedule.pop(self.search(name))

    def show_person(self, index):
        self.__class__._schedule[index].show_data()

    def show_data(self):
        for pessoa in self.__class__._schedule:
            pessoa.show_data()
            print('---------')


Persons().store_person('weliton', '09/12/1998', 1.66)
Persons().store_person('darice', '06/03/1999', 1.55)
Persons().store_person('fulano', '22/08/1997', 1.68)
Persons().store_person('ciclano', '11/09/2000', 1.70)
Persons().store_person('deltrano', '07/06/2001', 1.77)

print('segundo teste')
Persons().show_data()

print('\nsegundo teste')
print(Persons().search('deltrano'))

print('\nterceiro teste')
Persons().remove_person('deltrano')
Persons().show_data()

print('\nquarto teste')
Persons().show_person(1)
