# Euler's Number

from decimal import Decimal as D

if __name__ == '__main__':
    n = int(input())
    fact, ans = D(1), D(1)
    for i in range(1, n + 1):
        fact = fact * D(i)
        curr = D(1) / fact
        if curr < 0.000000000000001:
            break
        ans += curr
    print('%.13f' % ans)
