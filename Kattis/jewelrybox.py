from math import sqrt

# Jewelry Box

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        x, y = map(int, input().split())
        h = (x + y - sqrt(x ** 2 + y ** 2  - x * y)) / 6
        print(f'{h * (x - 2 * h) * (y - 2 * h):.10f}') 