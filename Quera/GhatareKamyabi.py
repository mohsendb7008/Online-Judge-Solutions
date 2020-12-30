if __name__ == '__main__':
    k, a, b = map(int, input().split())
    ans = abs(a - b)
    a1 = k * (a // k)
    a2 = a1 if a == a1 else a1 + k
    b1 = k * (b // k)
    b2 = b1 if b == b1 else b1 + k
    ans = min(ans, abs(a - a1) + abs(a1 - b1) // k + abs(b1 - b))
    ans = min(ans, abs(a - a1) + abs(a1 - b2) // k + abs(b2 - b))
    ans = min(ans, abs(a - a2) + abs(a2 - b1) // k + abs(b1 - b))
    ans = min(ans, abs(a - a2) + abs(a2 - b2) // k + abs(b2 - b))
    print(ans)