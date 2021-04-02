def solve(s, u, v):
    s, u, v = s % 2, u % 2, v % 2
    if s == 0:
        if u + v == 2:
            return 'YES'
        return 'NO'
    if u + v == 0:
        return 'YES'
    return 'NO'

if __name__ == '__main__':
    a, b, c = map(int, input().split())
    print(solve(a, b, c), solve(b, a, c), solve(c, a, b))