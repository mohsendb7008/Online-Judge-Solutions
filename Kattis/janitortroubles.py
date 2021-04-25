# Janitor Troubles

from math import sqrt

if __name__ == '__main__':
    a, b, c, d = map(float, input().split())
    s = (a + b + c + d) / 2
    print(sqrt((s - a) * (s - b) * (s - c) * (s - d)))
