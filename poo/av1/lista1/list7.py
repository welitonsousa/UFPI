def fatorial(n):
    if n <= 1:
        return 1
    return n * fatorial(n -1)
fat = 1
while fat > 0:
    fat = int(input())
    print(fatorial(fat))