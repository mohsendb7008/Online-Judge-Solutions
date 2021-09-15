# Beavergnaw

from math import pi

if __name__ == '__main__':
    while True:
        D, V = map(int, input().split())
        if D + V == 0:
            break
        print((D ** 3 - 6 * V / pi) ** (1 / 3))