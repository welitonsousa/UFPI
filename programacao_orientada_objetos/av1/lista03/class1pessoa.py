'''
Crie uma classe para representar uma pessoa, com os atributos privados de nome, data de nascimento e altura.
Crie os métodos públicos necessários para sets e gets e também um método para imprimir todos dados de uma
pessoa. Crie um método para calcular a idade da pessoa.
'''


from datetime import datetime


class Person:
    def __init__(self, name, birth, height):
        self._name = name
        self._height = height
        self._birth = birth

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, new_name):
        self._name = new_name

    @property
    def height(self):
        return self._height

    @height.setter
    def height(self, new_height):
        self._height = new_height

    def show_data(self):
        print('Nome: ', self._name)
        print('Nascimento: ', self._birth)
        print('Altura: ', self._height)

    def age(self):
        date_birth = datetime.strptime(self._birth, '%d/%m/%Y')
        today = datetime.today()
        return today.year - date_birth.year - ((today.month, today.day) < (date_birth.month, date_birth.day))


