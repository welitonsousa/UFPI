from datetime import datetime
from interface_accounts import Accounts


class CurrentAccount(Accounts):

    def __init__(self):
        self._number = datetime.now().microsecond
        self._balance = 0.0
        self._limit = 500
        self._historic = []

    @property
    def get_data_current_account(self):
        return {'number': self._number, 'balance': self._balance, 'limit': self._limit, 'historic': self._historic, }

    def pay_taxation(self, value):
        self._balance -= value
        historic = str(datetime.now()) + ' taxa de: ' + str(value) + ' reias'
        self._historic.append(historic)

    def update_limit(self, new_limit: float):
        if new_limit > self._limit:
            self._limit = new_limit
            print('Limite alterado')
        else:
            print('Limite menor que o limite atual')

    def deposit(self, value: float):
        if value > 0:
            self._balance += value
            historic = str(datetime.now()) + ' deposito de: ' + str(value) + ' reias'
            self._historic.append(historic)
            print('deposito realizado com sucesso')

    def withdraw(self, value: float):
        if value < self._balance:
            self._balance -= value
            historic = str(datetime.now()) + ' saque de: ' + str(value) + ' reias'
            self._historic.append(historic)
            print('saque realizado com sucesso')
        else:
            print('saldo insuficiente')

    def sun_money(self, value: float):
        self._balance += value

    def post_historic(self, historic: str):
        self._historic.append(historic)

    def send_money(self, number_send, clients_list: list):
        account_type = 0
        # 1 = current
        # 2 = saving

        account_receiver = False
        number_account_receiver_user_input = input('numero da conta que deseja transferir: ')

        for client in clients_list:
            if client.get_data_client['data']['current_account'] is not False:
                if str(client.get_data_client['data']['current_account']['number']) == number_account_receiver_user_input:
                    account_receiver = client
                    account_type = 1
                    break
            elif client.get_data_client['data']['saving_account'] is not False:
                if str(client.get_data_client['data']['saving_account']['number']) == number_account_receiver_user_input:
                    account_receiver = client
                    account_type = 2
                    break
        if account_receiver is not False:
            value_send = float(input('Valor da transferencia: '))
            if self._balance >= value_send:
                self._balance -= value_send
                historic = str(datetime.now()) + ' tranferido ' + str(value_send) + ' reais ' + 'para ' + number_account_receiver_user_input
                historic_receiver = str(datetime.now()) + ' ' + str(number_send) + ' te enviou ' + str(value_send) + ' reais '

                if account_type == 1:
                    account_receiver.sun_money_current(value_send)
                    account_receiver.post_historic_current(historic_receiver)
                elif account_type == 2:
                    account_receiver.sun_money_saving(value_send)
                    account_receiver.post_historic_saving(historic_receiver)

                self._historic.append(historic)
                print('transferencia realizada com sucesso')
        else:
            print('conta não encontrada')
