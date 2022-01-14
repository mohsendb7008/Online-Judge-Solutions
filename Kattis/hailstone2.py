# Hailstone Sequences

if __name__ == '__main__':
    n = int(input())
    ans = 0
    while True:
        ans += 1
        if n == 1:
            break
        if n % 2 == 0:
            n = n // 2
        else:
            n = 3 * n + 1
    print(ans)