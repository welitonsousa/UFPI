import abc


class Accounts(abc):

    @abc.abstractmethod
    def send_money(self):
        """method for sending money when making a transfer"""
        pass

    @abc.abstractmethod
    def post_historic(self):
        """method for adding a new item to your account history"""
        pass

    @abc.abstractmethod
    def deposit(self):
        """method for depositing money"""
        pass

    @abc.abstractmethod
    def withdraw(self):
        """method to withdraw money"""
        pass
