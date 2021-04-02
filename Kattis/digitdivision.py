# Digit Division

if __name__ == '__main__':
    n, m = map(int, input().split())
    d = input()
    rem, cnt = 0, 0
    for i in range(n):
        rem = rem * 10 + (ord(d[i]) - ord('0'))
        if rem % m == 0:
            rem = 0
            cnt += 1
    print((2 ** (cnt - 1)) % (1000000007) if rem == 0 else 0)