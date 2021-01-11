
class Person:

    def __init__(self, name: str, cpf: str, date_birth: str):
        self._name = name
        self._cpf = cpf
        self._date_birth = date_birth

    @property
    def get_data_person(self):
        return {'name': self._name, 'cpf': self._cpf, 'date_birth': self._date_birth}
