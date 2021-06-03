# Sjecista

if __name__ == '__main__':
    n = int(input())
    ans = 0
    for x in range(1, n-2):
        ans += x * (n-2 - x)
    print(ans * n // 4)