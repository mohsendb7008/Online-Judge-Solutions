if __name__ == '__main__':
    n, x, y = map(int, input().split())
    a = list(map(int, input().split()))
    found = False
    for i in range(n):
        extra, lack = (a[i] // x) * y, 0
        for j in range(n):
            if j != i:
                lack += 100 - a[j]
        if extra >= lack:
            found = True
            break
    print('YES' if found else 'NO')