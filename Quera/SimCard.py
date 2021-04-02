if __name__ == '__main__':
    while True:
        a, b = map(int, input().split())
        if a + b == 0:
            break
        print(min(30 * a + 40 * b, 35 * a + 30 * b, 40 * a + 20 * b))