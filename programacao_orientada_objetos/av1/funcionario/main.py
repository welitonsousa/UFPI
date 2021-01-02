from autenticavel import Autenticavel
from funcionario import Funcionario, Gerente
from sistema import Sistema

Autenticavel.register(Gerente)

gerente = Gerente('weliton', '1234')
funcionario = Funcionario('weliton')


print(Sistema().login(gerente))
print(Sistema().login(funcionario))
