from fractions import Fraction

# Temperature Confusion

a, b = map(int, input().split('/'))
f = Fraction(a, b)
ans = (f - Fraction(32, 1)) * Fraction(5, 9)
print(f'{ans.numerator}/{ans.denominator}')