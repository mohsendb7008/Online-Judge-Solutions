# Catalan Square

n = int(input())
c = 1
for i in range(1, n + 1):
    c *= 4 * i + 2
    c //= i + 2
print(c)