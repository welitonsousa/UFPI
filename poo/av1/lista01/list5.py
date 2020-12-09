base = int(input())
exp = int(input())
pot = 1
for i in range(0, exp):
    pot *= base
print(pot)