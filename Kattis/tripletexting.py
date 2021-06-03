# Triple Texting

if __name__ == '__main__':
    s = input()
    n = len(s)
    a, b, c = s[: n // 3], s[n // 3 : 2 * n // 3], s[2 * n // 3 :]
    if a == b == c:
        print(a)
    elif a == b:
        print(a)
    elif a == c:
        print(a)
    elif b == c:
        print(b)