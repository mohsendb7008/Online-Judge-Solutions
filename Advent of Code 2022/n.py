rocks = set()

def sign(x):
    if x > 0:
        return 1
    if x < 0:
        return -1
    return 0

def drawLine(x1, y1, x2, y2):
    rocks.add((x1, y1))
    dx = sign(x2 - x1)
    dy = sign(y2 - y1)
    while not (x1 == x2 and y1 == y2):
        x1 += dx
        y1 += dy
        rocks.add((x1, y1))

def dropSand(x, y, depth):
    if depth >= 500:
        return None
    if (x, y+1) not in rocks:
        return dropSand(x, y+1, depth+1)
    if (x-1, y+1) not in rocks:
        return dropSand(x-1, y+1, depth+1)
    if (x+1, y+1) not in rocks:
        return dropSand(x+1, y+1, depth+1)
    return (x, y)

while True:
    try:
        path = input().split(" -> ")
        assert len(path) > 1
        x, y = map(int, path[0].split(","))
        for i in range(1, len(path)):
            newX, newY = map(int, path[i].split(","))
            drawLine(x, y, newX, newY)
            x, y = newX, newY
    except KeyboardInterrupt:
        break

ans = 0
while True:
    sand = dropSand(500, 0, 1)
    if not sand:
        break
    rocks.add(sand)
    ans += 1
print(ans)