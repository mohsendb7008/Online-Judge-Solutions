elves = set()

i = 0
while True:
    try:
        for j, c in enumerate(input()):
            if c == '#':
                elves.add((i, j))
        i += 1
    except KeyboardInterrupt:
        break

def transform(x, y, dir):
    nx, ny = x, y
    if 'N' in dir:
        nx -= 1
    if 'S' in dir:
        nx += 1
    if 'W' in dir:
        ny -= 1
    if 'E' in dir:
        ny += 1
    return (nx, ny)

def exists(x, y, dir):
    return transform(x, y, dir) in elves

def move(x, y, r):
    t = r % 4
    if t == 0:
        if (not exists(x, y, 'N')) and (not exists(x, y, 'NE')) and (not exists(x, y, 'NW')):
            return 'N'
    elif t == 1:
        if (not exists(x, y, 'S')) and (not exists(x, y, 'SE')) and (not exists(x, y, 'SW')):
            return 'S'
    elif t == 2:
        if (not exists(x, y, 'W')) and (not exists(x, y, 'NW')) and (not exists(x, y, 'SW')):
            return 'W'
    elif t == 3:
        if (not exists(x, y, 'E')) and (not exists(x, y, 'NE')) and (not exists(x, y, 'SE')):
            return 'E'
    return None

def stays(x, y):
    return (not exists(x, y, 'N')) and (not exists(x, y, 'S')) and (not exists(x, y, 'W')) and (not exists(x, y, 'E')) and (not exists(x, y, 'NE')) and (not exists(x, y, 'NW')) and (not exists(x, y, 'SE')) and (not exists(x, y, 'SW'))

def play(r):
    replaces = {}
    for (elfx, elfy) in elves:
        if stays(elfx, elfy):
            continue
        for k in range(4):
            mov = move(elfx, elfy, r + k)
            if mov:
                place = transform(elfx, elfy, mov)
                if place not in replaces:
                    replaces[place] = []
                replaces[place].append((elfx, elfy))
                break
    for key, value in replaces.items():
        if len(value) == 1:
            elves.remove(value[0])
            elves.add(key)

for i in range(10):
    play(i)

X = list(map(lambda x: x[0], elves))
Y = list(map(lambda x: x[1], elves))
minX, maxX = min(X), max(X)
minY, maxY = min(Y), max(Y)

ans = 0
for x in range(minX, maxX + 1):
    for y in range(minY, maxY + 1):
        if (x, y) not in elves:
            ans += 1
print(ans)
