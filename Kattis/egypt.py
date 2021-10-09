# Egypt

if __name__ == '__main__':
    while True:
        a = list(map(int, input().split()))
        if sum(a) == 0:
            break
        a.sort()
        print('right' if a[0] ** 2 + a[1] ** 2 == a[2] ** 2 else 'wrong')