for _ in range(int(input())):
    n, S, a = map(int, input().split())
    print((S - a) // n if (S - a) >= n and (S - a) % n == 0 else -1)