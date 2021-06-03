# Prsteni

from fractions import Fraction as frac

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(1, n):
        f = frac(a[0], a[i])
        print(f'{f.numerator}/{f.denominator}')