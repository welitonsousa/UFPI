import datetime


class Cont:
    __balance = 0.0
    __date = 0
    __limit = 500.0
    __credit = __limit

    def __init__(self, client):
        if client.age() > 17:
            self.client = client
            self.__date = datetime.datetime.now()
        else:
            print('Cont not created')

    def data(self):
        return {
            'client_data': self.client.data(),
            'initial_date': self.__date,
            'balance': self.__balance,
            'credit': self.__credit,
            'limit': self.__limit
        }

    def add_balance(self, value_add):
        self.__balance += value_add

    def add_limit(self, value_add):
        self.__limit += value_add
        self.__credit += value_add

    def buy_credit(self, value_of_buy):
        if value_of_buy <= self.__credit:
            self.__credit -= value_of_buy
        else:
            print('insufficient credit')

    def buy_balance(self, value_of_buy):
        if value_of_buy <= self.__balance:
            self.__balance -= value_of_buy
        else:
            print('insufficient balance')

    def pay_credit(self):
        self.__credit = self.__limit

    def to_string(self):
        return 'Client data:\n' + self.client.to_string() + '\n\nCont data:' + \
               '\nInitial date: ' + str(self.__date) + '\nLimit: ' + str(self.__limit) + \
               '\nBalance: ' + str(self.__balance) + '\nCredit: ' + str(self.__credit)
