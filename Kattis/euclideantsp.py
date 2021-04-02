from math import log2, sqrt, fabs
from decimal import Decimal

# Euclidean TSP

def f(n: Decimal, p: Decimal, s: Decimal, v: Decimal, c: float):
    p1 = n * Decimal(log2(n)) ** Decimal(c * sqrt(2)) / (p * Decimal(1e9))
    p2 = s * Decimal(1 + 1 / c) / v
    return p1 + p2

if __name__ == "__main__":
    n, p, s, v = map(Decimal, input().split())
    lo, hi = 0.00001, 100000
    while fabs(hi - lo) > 0.0000001:
        m1, m2 = lo + (hi - lo) / 3, lo + 2 * (hi - lo) / 3
        f1, f2 = f(n, p, s, v, m1), f(n, p, s, v, m2)
        if f1 < f2:
            hi = m2
        else:
            lo = m1
    print(f(n, p, s, v, lo), lo)
        