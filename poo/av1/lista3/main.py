from data.cont import Cont
from data.client import Client

cont = Cont(Client('Weliton Sousa', 1234566, 18))

cont.buy_credit(600)
cont.buy_credit(400)
cont.add_limit(500)
cont.buy_credit(400)
cont.pay_credit()

cont.buy_balance(300)
cont.add_balance(500)
cont.buy_balance(300)

print(cont.to_string())
print(cont.client.data())
