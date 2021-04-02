def hash(i, k, m):
    return i * 101 * 11 + k * 11 + m

if __name__ == '__main__':
    a = list(map(int, input().split()))
    n = sum(a)
    b = []
    for i in range(10):
        for _ in range(a[i]):
            b.append(i)
    fact = [1]
    for i in range(1, 201):
        fact.append(fact[i - 1] * i)
    dp = [0 for _ in range(201 * 101 * 11)]
    for i in range(n, -1, -1):
        for k in range(0, (n + 1) // 2 + 1):
            for m in range(11):
                if i == n:
                    dp[hash(i, k, m)] = 1 if (k == (n + 1) // 2 and m == 0) else 0
                else:
                    dp[(hash(i, k, m))] = dp[hash(i + 1, k, (m - b[i] + 11) % 11)]
                    if k < (n + 1) // 2:
                        dp[(hash(i, k, m))] += dp[hash(i + 1, k + 1, (m + b[i]) % 11)]
    ans = dp[hash(0, 0, 0)]
    ans *= fact[n // 2]
    ans *= fact[(n + 1) // 2]
    for i in range(10):
        ans //= fact[a[i]]
    print(ans % (1000000007))
    