# Moscow Dream

if __name__ == '__main__':
    a, b, c, n = map(int, input().split())
    print('YES' if a > 0 and b > 0 and c > 0 and n >= 3 and a + b + c >= n else 'NO')