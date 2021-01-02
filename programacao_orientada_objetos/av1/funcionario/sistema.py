from autenticavel import Autenticavel

class Sistema():
    def login(self, func):
        if isinstance(func, Autenticavel):
            return func.autentica('1234')
        return False