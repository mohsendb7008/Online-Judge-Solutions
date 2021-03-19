# Dice Cup

if __name__ == '__main__':
    n, m = map(int, input().split())
    p = [0 for _ in range(n + m + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
                p[i + j] += 1
    ans = max(p)
    for i in range(2, n + m + 1):
        if p[i] == ans:
            print(i)