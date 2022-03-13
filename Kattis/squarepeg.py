# Square Peg

if __name__ == '__main__':
    L, R = map(int, input().split())
    print('fits' if L ** 2 <= 2 * R ** 2 else 'nope')
