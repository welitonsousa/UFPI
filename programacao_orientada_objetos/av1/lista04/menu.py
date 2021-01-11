from client import Client
from employee import Employee
from current_account import CurrentAccount
from saving_account import SavingAccount


class Menu:

    def show(self):
        print('\n1 - cadastrar funcionario')
        print('2 - mostrar funcionarios')
        print('3 - cadastrar cliente')
        print('4 - mostrar clientes')
        print('5 - criar conta corrente')
        print('6 - criar conta poupanca')
        print('7 - operacao bancaria')
        print('8 - seguro de vida')
        print('9 - taxação')
        print('10 - detalhes do banco')
        print('0 - sair')

    def show_bank_details(self, clients):
        for client in clients:
            print('-------------------------------------------------')
            print('nome: ', client.get_data_client['person']['name'])
            print('quantidade de seguros de vida: ', len(client.get_data_client['life_insurance']))
            total_account = 0
            if client.get_data_client['data']['current_account'] is not False:
                total_account += 1
            if client.get_data_client['data']['saving_account'] is not False:
                total_account += 1
            print('quantidade de contas: ', total_account)
            print('-------------------------------------------------')
        print('Total de clientes: ', len(clients))

    def post_employee(self, employee_list):
        employee_list.append(Employee(input('nome: '), input('cpf: '), input('data de nascimento: '), float(input('salario: '))))

    def post_client(self, client_list):
        client_list.append(Client(input('nome: '), input('cpf: '), input('data de nascimento: '), input('profissão: '), float(input('renda: '))))

    def post_account_current(self, clients):
        if len(clients) > 0:
            Menu().get_clients(clients)
            cpf = input('CPF do cliente: ')

            is_client = False
            for client in clients:
                if client.get_data_client['person']['cpf'] == cpf:
                    is_client = True
                    if client.get_data_client['data']['current_account'] is False:
                        client.create_current_account(CurrentAccount())
                        print('Conta corrente criada')
                        client.update_limit(5000)
                    else:
                        print('este cliente ja possui uma conta corrente')
                    break
            if not is_client:
                print('cpf não encontrado')
        else:
            print('Nenhum cliente cadastrado')

    def post_account_saving(self, clients):
        if len(clients) > 0:
            Menu().get_clients(clients)
            cpf = input('CPF do cliente: ')

            is_client = False
            for client in clients:
                if client.get_data_client['person']['cpf'] == cpf:
                    is_client = True
                    if client.get_data_client['data']['saving_account'] is False:
                        client.create_saving_account(SavingAccount())
                        print('Conta poupanca criada')
                    else:
                        print('este cliente ja possui uma conta corrente')
                    break
            if not is_client:
                print('cpf não encontrado')
        else:
            print('Nenhum cliente cadastrado')

    def operation(self, clients):

        cpf = input('CPF: ')

        is_client = False
        for client in clients:
            if client.get_data_client['person']['cpf'] == cpf:
                is_client = True

                print('1 - depositar')
                print('2 - sacar')
                print('3 - transferir')

                user_input = int(input('opcao: '))
                if user_input == 1:
                    client.deposit(float(input('valor: ')))
                elif user_input == 2:
                    client.withdraw(float(input('valor: ')))
                elif user_input == 3:
                    client.transfer(clients)

                break
        if not is_client:
            print('cpf não encontrado')

    def get_employees(self, employees):
        for employee in employees:
            print(employee.get_data_employee)

    def get_clients(self, clients):
        for client in clients:
            print(client.get_data_client)

    def life_insurance(self, clients):
        if len(clients) > 0:
            Menu().get_clients(clients)
            cpf = input('CPF do cliente: ')

            is_client = False
            for client in clients:
                if client.get_data_client['person']['cpf'] == cpf:
                    is_client = True
                    value_life = float(input('valor total do seguro de vida: '))
                    client.post_life_insurance(value_life)
                    print('seguro adquerido')
                    break
            if not is_client:
                print('cpf não encontrado')
        else:
            print('Nenhum cliente cadastrado')

    def taxation(self, clients):
        if len(clients) > 0:
            Menu().get_clients(clients)
            cpf = input('CPF do cliente: ')

            is_client = False
            for client in clients:
                if client.get_data_client['person']['cpf'] == cpf:
                    is_client = True

                    if client.get_data_client['data']['current_account'] is False:
                        print('cliente sem conta corrente')
                    else:
                        total_value_life = 0.0
                        if len(client.get_data_client['life_insurance']) > 0:
                            for life in client.get_data_client['life_insurance']:
                                total_value_life += life['total_value']
                            total_value_life *= 0.02

                        total_value_current_account = client.get_data_client['data']['current_account']['balance']
                        total_value_current_account *= 0.01

                        client.post_taxation(total_value_life + total_value_current_account + 10.0)
                        print('taxação paga')
                    break
            if not is_client:
                print('cpf não encontrado')
        else:
            print('Nenhum cliente cadastrado')