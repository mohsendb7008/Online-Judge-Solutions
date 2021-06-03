# Sok

if __name__ == '__main__':
    a, b, c = map(int, input().split())
    i, j, k = map(int, input().split())
    frac = min(a / i, b / j, c / k)
    print(a - i * frac, b - j * frac, c - k * frac)