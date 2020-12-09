def showArray(array):
    for i in array:
        if type(i) == list:
            showArray(i)
        else:
            print(i)
showArray([1,2,3, [4,5,6, [7,8,9]]])