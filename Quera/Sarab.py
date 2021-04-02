x1, y1, x2, y2, mem = 0, 0, 2, 0, {}
for i in range(0, 10000, 4):
    mem[(x1, y1)] = i
    x1 += 1
    y1 += 1
    mem[(x1, y1)] = i+1
    x1 += 1
    y1 += 1
    mem[(x2, y2)] = i+2
    x2 += 1
    y2 += 1
    mem[(x2, y2)] = i+3
    x2 += 1
    y2 += 1
for i in range(int(input())):
    x, y = map(int, input().split())
    print(mem.get((x, y), -1))