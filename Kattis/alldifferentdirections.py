# All Different Directions

from math import radians, sin, cos, hypot

def solve():
    line = input().split()
    x, y = map(float, line[:2])
    a = float(line[3])
    for i in range(4, len(line), 2):
        if line[i] == 'turn':
            a += float(line[i+1])
        elif line[i] == 'walk':
            x += float(line[i+1]) * cos(radians(a))
            y += float(line[i+1]) * sin(radians(a))
    return x, y

if __name__ == '__main__':
    while True:
        n = int(input())
        if n == 0:
            break
        targets = [solve() for _ in range(n)]
        a, b = sum(map(lambda x: x[0], targets)) / n, sum(map(lambda x: x[1], targets)) / n
        print(f'{a:.5f} {b:.5f} {max(map(lambda x: hypot(x[0] - a, x[1] - b), targets)):.5f}')