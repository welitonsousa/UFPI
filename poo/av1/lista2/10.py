import random
def createArray(init = 0,last = 100):
    array = []
    for i in range(init, last):
        array.append(random.randrange(0, 101))
    return array

def calc(array = []):
    array.sort()
    sizeArray = len(array)
    calc = {
            'media': 0,
            'mediana': 0,
            'varianca': 0,
            'desvio': 0
            }
    for index in array:
        calc['media'] += index
    calc['media'] = calc['media']/sizeArray
    
    for index in array:
        calc['varianca'] += (index - calc['media']) ** 2
    calc['varianca'] = calc['varianca']/sizeArray
    calc['desvio'] = calc['varianca'] ** (1/2)
    if sizeArray % 2 == 0:
        calc['mediana'] = (array[int(len(array)/2)] + array[int(len(array)/2) + 1]) / 2
    else:
        calc['mediana'] = array[int(len(array)/2)]
    return calc

array = createArray()
calc = calc(array)
print(calc)
