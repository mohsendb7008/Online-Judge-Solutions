# ICPC Tutorial

from math import log2, ceil

def T(t, n, m):
    if t == 1:
        ans = 1
        for i in range(n):
            ans *= (i + 1)
            if ans > m:
                return False
        return True
    elif t == 2:
        ans = 1
        for i in range(n):
            ans *= 2
            if ans > m:
                return False
        return True
    elif t == 3:
        return n ** 4 <= m
    elif t == 4:
        return n ** 3 <= m
    elif t == 5:
        return n ** 2 <= m
    elif t == 6:
        return ceil(n * log2(n)) <= m
    return n <= m

if __name__ == '__main__':
    m, n, t = map(int, input().split())
    print('AC' if T(t, n, m) else 'TLE')
