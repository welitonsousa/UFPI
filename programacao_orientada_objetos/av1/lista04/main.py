from menu import Menu

employees = []
clients = []

while True:

    Menu().show()
    user_input = int(input())

    if user_input == 1:
        Menu().post_employee(employees)

    elif user_input == 2:
        Menu().get_employees(employees)

    elif user_input == 3:
        Menu().post_client(clients)

    elif user_input == 4:
        Menu().get_clients(clients)

    elif user_input == 5:
        Menu().post_account_current(clients)

    elif user_input == 6:
        Menu().post_account_saving(clients)

    elif user_input == 7:
        Menu().operation(clients)

    elif user_input == 8:
        Menu().life_insurance(clients)

    elif user_input == 9:
        Menu().taxation(clients)

    elif user_input == 10:
        Menu().show_bank_details(clients)

    elif user_input == 0:
        break
