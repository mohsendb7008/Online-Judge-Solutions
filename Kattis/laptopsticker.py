# Laptop Sticker

if __name__ == '__main__':
    x, y, a, b = map(int, input().split())
    print(1 if (a <= x-2 and b <= y-2) else 0)