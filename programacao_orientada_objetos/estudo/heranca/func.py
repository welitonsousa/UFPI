from teste.funcTeste import Teste

class Funcionario:
    def __init__(self, name: str, cpf: str, salario: float):
        self.name = name
        self.cpf = cpf
        self.salario: salario

    @property
    def get_data(self):
        print(self.name, self.cpf)

class Gerente (Funcionario):
    def __init__(self, name: str, cpf: str, salario: float, senha: str):
        super().__init__(name, cpf, salario)
        self.senha = senha

    @property
    def get_data(self):
        print('trolei')


class Secretaria (Funcionario):
    def __init__(self, name: str, cpf: str, salario: float):
        super().__init__(name, cpf, salario)


gerente = Gerente('weliton', '019238-12', 2000.00, '12343')
funcionario = Secretaria('Darice', '01912348-12', 20000.00)
gerente.get_data
funcionario.get_data