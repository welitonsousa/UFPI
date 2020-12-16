def reverse(array):
    lastPosition = len(array) - 1
    for i in range(0, int(len(array)/2)):
        array[i], array[lastPosition] = array[lastPosition], array[i]
        lastPosition -= 1
    return array

def createArray(init, last):
    array = []
    for i in range(init, last):
        array.append(i)
    return array

array = createArray(0,10)
print(array)
array = reverse(array)
print(array)