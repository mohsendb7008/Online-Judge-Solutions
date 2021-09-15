from math import radians, cos, sin

# Vacuumba

if __name__ == '__main__':
    for _ in range(int(input())):
        alpha, x, y = radians(90), 0, 0
        for _ in range(int(input())):
            a, d = map(float, input().split())
            alpha += radians(a)
            x += d * cos(alpha)
            y += d * sin(alpha)
        print(f'{x:.6f} {y:.6f}')