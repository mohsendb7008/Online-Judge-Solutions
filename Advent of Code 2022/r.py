adjX = [0, 0, 0, 0, 1, -1]
adjY = [0, 0, 1, -1, 0, 0]
adjZ = [1, -1, 0, 0, 0, 0]
points = set()

try:
    while True:
        x, y, z = map(int, input().split(','))
        points.add((x, y, z))
except KeyboardInterrupt:
    pass

ans = 0
for p in points:
    for k in range(6):
        x = p[0] + adjX[k]
        y = p[1] + adjY[k]
        z = p[2] + adjZ[k]
        if (x, y, z) not in points:
            ans += 1
print(ans)
