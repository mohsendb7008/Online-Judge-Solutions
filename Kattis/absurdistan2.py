# Absurdistan Roads II

if __name__ == '__main__':
    n = int(input())
    c = {}
    for i in range(n+1):
        for j in range(i+1):
            if j == 0 or j == i:
                c[(i, j)] = 1
            else:
                c[(i, j)] = c[(i-1, j)] + c[(i-1, j-1)]
    a = [0, 0, 0, 0]
    for i in range(4, n+1):
        ai = 0
        for k in range(2, i-1):
            ai += c[(i-1, k-1)] * ((k - 1) ** k - a[k]) * (i - k - 1) ** (i - k)
        a.append(ai)
    print(1 - a[n] / ((n - 1) ** n))
