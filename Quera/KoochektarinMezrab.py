p, d = map(int, input().split())
for ans in range(d, 1000000000, d):
    if 0 <= ans % p <= p // 2:
        print(ans)
        break