# Bobby's Bet
n = int(input())
fact = [1, 1]
for i in range(2, 11):
    fact.append(i * fact[i - 1])
for _ in range(n):
    r, s, x, y, w = map(int, input().split())
    sum_ = 0
    for i in range(x, y + 1):
        sum_ += (fact[y] / (fact[i] * fact[y - i])) * w * (((s - r + 1) / s) ** i) * (((r - 1) / s) ** (y - i))
    if sum_ > 1:
        print('yes')
    else:
        print('no')