l = []
while (x:=int(input())) != 0:
    l.append(x)
print('\n'.join(map(str, reversed(l))))