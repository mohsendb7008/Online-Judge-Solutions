# Cafeteria (Easy)
if __name__ == '__main__':
    monsters = [[0, 0, 0, 0] for _ in range(5)]
    line = input().split()
    unk = 0
    for i in range(10):
        dish = line[i]
        if dish == '_':
            unk += 1
            continue
        monsters[i//2][i%2] = int(dish)
    line = input().split()
    for i in range(10):
        dish = line[i]
        if dish == '_':
            unk += 1
            continue
        monsters[i//2][2+i%2] = int(dish)
    used = set()
    while unk > 0:
        for i in range(5):
            for a in range(4):
                for b in range(a + 1, 4):
                    if monsters[i][a] == 0 or monsters[i][b] == 0 or (i, a, b) in used:
                        continue
                    used.add((i, a, b))
                    for j in range(5):
                        # monsters[i][a] / monsters[i][b] == monsters[j][a] / monsters[j][b]
                        if monsters[j][a] == 0 and monsters[j][b] != 0:
                            monsters[j][a] = (monsters[i][a] * monsters[j][b]) // monsters[i][b]
                            unk -= 1
                        if monsters[j][a] != 0 and monsters[j][b] == 0:
                            monsters[j][b] = (monsters[i][b] * monsters[j][a]) // monsters[i][a]
                            unk -= 1
    for i in range(10):
        print(monsters[i//2][i%2], end=' ')
    print()
    for i in range(10):
        print(monsters[i//2][2+i%2], end=' ')
    print()
