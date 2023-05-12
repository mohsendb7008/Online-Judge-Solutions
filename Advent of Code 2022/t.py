l = []
while True:
    try:
        l.append((int(input()), False))
    except KeyboardInterrupt:
        break
n = len(l)
finish = False
while not finish:
    finish = True
    for i in range(n):
        if l[i][1] == False:
            a, _ = l.pop(i)
            l.insert((i + a + (n - 1) * 1000) % (n - 1), (a, True))
            finish = False
            break
zero = l.index((0, True))
print(l[(zero + 1000) % n][0] + l[(zero + 2000) % n][0] + l[(zero + 3000) % n][0])

