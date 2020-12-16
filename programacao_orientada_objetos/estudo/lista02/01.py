placas = 0
while True:
    userInput = input()
    if userInput == 'antigas':
        print(placas)
        break
    elif ' ' in userInput and len(userInput) == 8:
        letras = userInput.split(' ')[0]
        numeros = userInput.split(' ')[1]
        
        if numeros.isdigit() and letras.isupper():
            placas += 1
