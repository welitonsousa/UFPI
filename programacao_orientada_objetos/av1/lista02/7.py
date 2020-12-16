def multiplyArrays(arrayOne, arrayTwo):
    arrayTree = []
    for i in range(0, len(arrayOne)):
        arrayTree.append(arrayOne[i] * arrayTwo[i])
    return arrayTree

arrayTree = multiplyArrays([1,2,3,4,5], [2,2,2,2,2])
print(arrayTree)