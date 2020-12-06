inputData = int(input())
user_coord = {'N': 0, 'S': 0, 'L': 0, 'O': 0}

for i in range(0, inputData):
    coord = input().split(' ')
    user_coord[coord[0]] += int(coord[1])

if user_coord['N'] > user_coord['S']:
    user_coord['N'] -= user_coord['S']
    user_coord['S'] = 0
else:
    user_coord['S'] -= user_coord['N']
    user_coord['N'] = 0

if user_coord['L'] > user_coord['O']:
    user_coord['L'] -= user_coord['O']
    user_coord['O'] = 0
else:
    user_coord['O'] -= user_coord['L']
    user_coord['L'] = 0

user_coord['N'], user_coord['S'] = user_coord['S'], user_coord['N']
user_coord['L'], user_coord['O'] = user_coord['O'], user_coord['L']

print(user_coord['N'], ' ', user_coord['S'], ' ', user_coord['L'], ' ', user_coord['O'])
