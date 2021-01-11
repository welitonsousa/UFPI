from person import Person
from life_insurance import LifeInsurance
from datetime import datetime


class Client(Person, LifeInsurance):

    def __init__(self, name: str, cpf: str, date_birth: str, profession: str, income: str):
        super().__init__(name, cpf, date_birth)
        self._profession = profession
        self._income = income
        self._saving_account = False
        self._current_account = False
        self._life_insurance = []
        self._taxation = []

    @property
    def get_data_client(self):
        life = []
        for safe in self._life_insurance:
            life.append(safe.get_data_life)
        return {'person': self.get_data_person, 'life_insurance': life, 'taxation': self._taxation, 'data': {'profession': self._profession, 'income': self._income, 'saving_account': self._is_saving(), 'current_account': self._is_current()}}

    def post_taxation(self, value: float):
        taxation = str(datetime.now()) + ' taxa de ' + str(value) + ' reais'
        self._taxation.append(taxation)
        self.pay_taxation(value)

    def post_life_insurance(self, value):
        self._life_insurance.append(LifeInsurance(value))

    def create_saving_account(self, saving_account):
        self._saving_account = saving_account

    def create_current_account(self, current_account):
        self._current_account = current_account

    def _is_saving(self):
        if self._saving_account is False:
            return self._saving_account
        return self._saving_account.get_data_saving_account

    def _is_current(self):
        if self._current_account is False:
            return self._current_account
        return self._current_account.get_data_current_account

    def update_limit(self, new_limit):
        if self._current_account is not False:
            self._current_account.update_limit(new_limit)

    def pay_taxation(self, value):
        self._current_account.pay_taxation(value)

    def deposit(self, value):
        if self._current_account is False and self._saving_account is False:
            print('nenhuma conta cadastrada')

        elif self._current_account is not False and self._saving_account is not False:
            user_input = int(input('1 - conta corrente\n2 - conta poupanca\nopcao: '))
            if user_input == 1:
                self._current_account.deposit(value)
            elif user_input == 2:
                self._saving_account.deposit(value)

        elif self._current_account is not False:
            print('entrei na corrente')
            self._current_account.deposit(value)

        elif self._saving_account is not False:
            self._saving_account.deposit(value)

    def withdraw(self, value):
        if self._current_account is False and self._saving_account is False:
            print('nenhuma conta cadastrada')

        elif self._current_account is not False and self._saving_account is not False:
            user_input = int(input('1 - conta corrente\n2 - conta poupanca\nopcao: '))
            if user_input == 1:
                self._current_account.withdraw(value)
            elif user_input == 2:
                self._saving_account.withdraw(value)

        elif self._current_account is not False:
            self._current_account.withdraw(value)

        elif self._saving_account is not False:
            self._saving_account.withdraw(value)

    def transfer(self, clients_list):
        if self._current_account is False and self._saving_account is False:
            print('nenhuma conta cadastrada')

        elif self._current_account is not False and self._saving_account is not False:
            user_input = int(input('1 - conta corrente\n2 - conta poupanca\nopcao: '))
            if user_input == 1:
                self._current_account.send_money(self._current_account.get_data_current_account['number'], clients_list)
            elif user_input == 2:
                self._saving_account.send_money(self._saving_account.get_data_saving_account['number'], clients_list)

        elif self._current_account is not False:
            self._current_account.send_money(self._current_account.get_data_current_account['number'], clients_list)

        elif self._saving_account is not False:
            self._saving_account.send_money(self._saving_account.get_data_saving_account['number'], clients_list)

    def sun_money_current(self, value):
        self._current_account.sun_money(value)

    def sun_money_saving(self, value):
        self._saving_account.sun_money(value)

    def post_historic_current(self, historic: str):
        self._current_account.post_historic(historic)

    def post_historic_saving(self, historic: str):
        self._saving_account.post_historic(historic)
