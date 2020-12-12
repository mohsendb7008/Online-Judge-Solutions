# Broken Calculator

if __name__ == '__main__':
    m, n = 1, int(input())
    for i in range(n):
        a, c, b = input().split()
        a, b = int(a), int(b)
        if c == '+':
            m = a + b - m
            print(m)
        elif c == '-':
            m = (a - b) * m
            print(m)
        elif c == '*':
            m = (a * b) ** 2
            print(m)
        elif c == '/':
            m = a // 2 + a % 2
            print(m)
