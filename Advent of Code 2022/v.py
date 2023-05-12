import re

grid = {}
n, m, pos = 0, 0, None

while True:
    line = input()
    if not line or line.isspace():
        break
    for j, c in enumerate(line):
        if c != ' ':
            grid[(n, j)] = c
            if c == '.' and not pos:
                pos = (n, j)
    n += 1
    m = max(m, len(line))

adjR = [0, 1, 0, -1]
adjC = [1, 0, -1, 0]
dir = 0

def move():
    global pos
    x, y = pos
    while True:
        x = (x + adjR[dir] + n) % n
        y = (y + adjC[dir] + m) % m
        if (x, y) not in grid:
            continue
        if grid[(x, y)] == '.':
            break
        if grid[(x, y)] == '#':
            return
    pos = (x, y)

instructions = re.findall(r'(\d+|R|L)', input())
for ins in instructions:
    if ins == 'R':
        dir = (dir + 1) % 4
    elif ins == 'L':
        dir = (dir + 3) % 4
    else:
        for _ in range(int(ins)):
            move()

print(1000 * (pos[0] + 1) + 4 * (pos[1] + 1) + dir)