# Different Distances

if __name__ == '__main__':
    while True:
        line = input()
        if line.strip() == '0':
            break
        x1, y1, x2, y2, p = map(float, line.split())
        f = lambda z1, z2: abs(z1 - z2) ** p
        print((f(x1, x2) + f(y1, y2)) ** (1 / p))