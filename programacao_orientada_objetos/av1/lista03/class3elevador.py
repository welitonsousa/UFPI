"""
Crie uma classe denominada Elevador para armazenar as informações de um elevador dentro de um prédio. A
classe deve armazenar o andar atual (térreo = 0), total de andares no prédio (desconsiderando o térreo),
capacidade do elevador e quantas pessoas estão presentes nele. A classe deve também disponibilizar os
seguintes métodos:
a. Inicializa : que deve receber comorâ pametros a capacidade do elevador e o total de andares no
prédio (os elevadores sempre começam no térreo e vazio);
b. Entra : para acrescentar uma pessoa no elevador (só deve acrescentar se ainda houver espaço);
c. Sai : para remover uma pessoa do elevador (só deve remover se houver alguém dentro dele);
d. Sobe : para subir um andar (não deve subir se já estiver no último andar);
e. Desce : para descer um andar (não deve descer se já estiver no térreo);
f. Encapsular todos os atributos da classe (atributos privados e criar os métodos set e get).
g. Criar um menu iterativo para controlar as operações do elevador.
"""


class Elevator:
    _total_floors = 0
    _max_capacity = 0
    _total_persons = 0
    _current_floor = 0

    def __init__(self, total_floors, max_capacity):
        self.__class__._total_floors = total_floors
        self.__class__._max_capacity = max_capacity

    def menu(self):
        print('1 - Entrar')
        print('2 - Sair')
        print('3 - Subir')
        print('4 - Descer')
        print('0 - Sair')
        return int(input())

    def exit(self):
        if self.__class__._total_persons > 0:
            self.__class__._total_persons -= 1
            print('Uma pessoa saiu')
        else:
            print('O elevador esta vazio')

    def enter(self):
        if self.__class__._total_persons < self.__class__._max_capacity:
            self.__class__._total_persons += 1
            print('Uma pessoa entrou')
        else:
            print('O elevador esta cheio')

    def up(self):
        if self.__class__._current_floor < self.__class__._total_floors:
            self.__class__._current_floor += 1
            print('Uma elevador subiu mais um andar')
        else:
            print('O elevador esta no ultimo andar')

    def down(self):
        if self.__class__._current_floor > 0:
            self.__class__._current_floor -= 1
            print('Uma elevador desceu um andar')
        else:
            print('O elevador esta no terreo')

    @property
    def total_floors(self):
        return self.__class__._total_floors

    @total_floors.setter
    def total_floors(self, new_floors):
        self.__class__._total_floors = new_floors

    @property
    def max_capacity(self):
        return self.__class__._max_capacity

    @max_capacity.setter
    def max_capacity(self, new_max_capacity):
        self.__class__._max_capacity = new_max_capacity

    @property
    def total_persons(self):
        return self.__class__._total_persons

    @total_floors.setter
    def total_persons(self, new_total_persons):
        self.__class__._total_persons = new_total_persons

    @property
    def current_floor(self):
        return self.__class__._current_floor

    @total_floors.setter
    def current_floor(self, new_current_floor):
        self.__class__._current_floor = new_current_floor

floors = int(input('Andares do predio: '))
max_capacity = int(input('Capacidade maxima do elevador: '))

elevator = Elevator(floors, max_capacity)
while True:
    option = elevator.menu()
    if option == 0:
        break
    elif option == 1:
        elevator.enter()
    elif option == 2:
        elevator.exit()
    elif option == 3:
        elevator.up()
    elif option == 4:
        elevator.down()
