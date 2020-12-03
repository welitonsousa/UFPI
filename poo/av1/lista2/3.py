def find(array, character):
    index = 0
    for i in array:
        index += 1
        if i == character:
            return index
print(find('Teste', 'T'))