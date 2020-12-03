class Client:
    __cpf = 0
    __age = 0

    def __init__(self, name, cpf, age):
        self.name = name
        self.__cpf = cpf
        self.__age = age

    def data(self):
        return {
            'name': self.name,
            'age': self.__age,
            'cpf': self.__cpf,
        }

    def to_string(self):
        return 'Client: ' + self.name + '\nCPF: ' + str(self.__cpf) + '\nAge: ' + str(self.__age)

    def age(self):
        return self.__age

    def birthday(self):
        self.__age += 1
