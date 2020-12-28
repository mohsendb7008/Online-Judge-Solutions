from decimal import Decimal as de
n, mod = de(input()), 1000000007
print(int(n ** de(2) / de(48) + de(0.5)) % mod if n % 2 == 0 else int((n + de(3)) ** de(2) / de(48) + de(0.5)) % mod)