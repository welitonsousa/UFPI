
class Funcionario():
    def __init__(self, nome):
        self._nome = nome


class Gerente(Funcionario):

    def __init__(self, nome, senha):
        super().__init__(nome)
        self._senha = senha

    def autentica(self, senha:str):
        if (self._senha == senha):
            return True
        return False