x1, x2 = map(int, input().split())
if x1 == x2:
    print('Saal Noo Mobarak!')
elif x1 < x2:
    for i in range(x2 - x1):
        print('R', end='')
    print()
else:
    for i in range(x1 - x2):
        print('L', end='')
    print()