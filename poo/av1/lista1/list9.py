def fib(a, b, c):
    if c <= term:
        print(a)
        return fib(b, a + b, c + 1)

term = int(input())
fib(0, 1, 0)