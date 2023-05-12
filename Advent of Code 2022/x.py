import sys

# n = 4
n = 25
takenM = set()
takenN = set()

i = 0
while True:
    try:
        line = input()
        m = len(line) - 2
        for j, c in enumerate(line):
            x, y = i-1, j-1
            if c == '>':
                for k in range(m):
                    takenM.add((x, (y + k) % m, k))
            elif c == '<':
                for k in range(m):
                    takenM.add((x, (y - k + m) % m, k))
            elif c == '^':
                for k in range(n):
                    takenN.add(((x - k + n) % n, y, k))
            elif c == 'v':
                for k in range(n):
                    takenN.add(((x + k) % n, y, k))
        i += 1
    except KeyboardInterrupt:
        break

def isValid(x, y, k):
    if (x, y) in ((-1, 0), (n, m-1)):
        return True
    return x >= 0 and x < n and y >= 0 and y < m and (x, y, k % m) not in takenM and (x, y, k % n) not in takenN

vis = {(-1, 0, 0)}
bfs = [(-1, 0, 0)]
adjR = [0, 0, 0, 1, -1]
adjC = [0, 1, -1, 0, 0]

while bfs:
    x, y, k = bfs.pop(0)
    for t in range(5):
        xx, yy, kk = x + adjR[t], y + adjC[t], k + 1
        if isValid(xx, yy, kk) and (xx, yy, kk) not in vis:
            if (xx, yy) == (n, m-1):
                print(kk)
                sys.exit(0)
            vis.add((xx, yy, kk))
            bfs.append((xx, yy, kk))