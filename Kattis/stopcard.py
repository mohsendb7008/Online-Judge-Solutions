from decimal import Decimal

# Stop Card

fact = [1]

if __name__ == "__main__":
    for i in range(1, 65):
        fact.append(fact[-1] * i)
    n, c = map(int, input().split())
    cards = list(map(int, input().split()))
    cards.sort()
    ans = 0
    if c == 0:
        for i in range(n):
            ans += cards[i] * (fact[n-1])
    else:
        for i in range(n):
            p = 0
            for j in range(c, i + 1):
                p += (fact[i] * fact[n - j - 1] * c) / (j * fact[i - j])
            if i != n-1:
                p += c * fact[n-2]
            ans += cards[i] * p
    print("%.6f\n" %(Decimal(ans) / Decimal(fact[n])))