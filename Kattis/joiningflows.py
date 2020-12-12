# Joining Flows

if __name__ == '__main__':
    k = int(input())
    faucets = []
    suma, sumb, sumta, sumtb = 0, 0, 0, 0 
    for i in range(k):
        t, a, b = map(int, input().split())
        faucets.append((t, a, b))
        suma += a
        sumb += b
        sumta += t * a
        sumtb += t * b
    faucets.sort()
    q = int(input())
    for j in range(q):
        T, F = map(int, input().split())
        try:
            assert suma <= F <= sumb
            assert sumta <= T * F <= sumtb
            rem, lower = F - suma, sumta
            for i in range(k):
                di = min(faucets[i][2] - faucets[i][1], rem)
                rem -= di
                lower += di * faucets[i][0]
            rem, upper = sumb - F, sumtb
            for i in range(k):
                di = min(faucets[i][2] - faucets[i][1], rem)
                rem -= di
                upper -= di * faucets[i][0]
            assert lower <= T * F <= upper
            print('yes')
        except AssertionError:
            print('no')
