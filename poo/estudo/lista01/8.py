def frequencia(my_list):
    freq = {}
    for item in my_list:
        if (item in freq):
            freq[item] += 1
        else:
            freq[item] = 1
    return freq

def chr_remove(old, to_remove):
    new_string = old
    for x in to_remove:
        new_string = new_string.replace(x, '')
    return new_string

def sort(array, array2):
    for p in range(0, len(array)):
        current_element = array[p]
        current_element2 = array2[p]
        while p > 0 and array[p - 1] > current_element:
            array[p] = array[p - 1]
            array2[p] = array2[p - 1]
            p -= 1

        array[p] = current_element
        array2[p] = current_element2

frase = input().lower()
palavras = chr_remove(frase, "$(#.,").split(' ')
palavras.sort()

dic = frequencia(palavras)

lista_valores = []
lista_chaves = []
for palavra, freq in dic.items():
    lista_chaves.append(palavra)
    lista_valores.append(freq)

sort(lista_valores, lista_chaves)
lista_valores.reverse()
lista_chaves.reverse()
for index in range(0, len(lista_chaves)):
    print(lista_chaves[index], lista_valores[index])
