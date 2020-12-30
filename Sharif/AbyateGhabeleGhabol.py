def diff(s, t):
    ans = 0
    for a, b in zip(s, t):
        if a != b:
            ans += 1
    return ans

if __name__ == '__main__':
    n = int(input())
    s = input()
    all = []
    for i in range(n):
        all.append('0' * i + '1' * (n - i))
    for i in range(n):
        all.append('1' * i + '0' * (n - i))
    ans = n
    for t in all:
        ans = min(ans, diff(s, t))
    print(ans)
