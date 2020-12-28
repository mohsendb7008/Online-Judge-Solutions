# Continued Fraction

from fractions import Fraction as frac

def to_frac(u, i):
    if i == len(u) - 1:
        return frac(u[i])
    return frac(u[i]) + frac(1) / to_frac(u, i+1)

def to_q(u):
    if u.denominator == 1:
        return [u.numerator]
    return [u.numerator // u.denominator] + to_q(frac(u.denominator, u.numerator % u.denominator))

if __name__ == '__main__':
    input()
    u = list(map(int, input().split()))
    v = list(map(int, input().split()))
    u, v = to_frac(u, 0), to_frac(v, 0)
    print(' '.join(map(str, to_q(u + v))))
    print(' '.join(map(str, to_q(u - v))))
    print(' '.join(map(str, to_q(u * v))))
    print(' '.join(map(str, to_q(u / v))))

