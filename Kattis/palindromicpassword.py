# Palindromic Password

if __name__ == '__main__':
    palins = []
    for i in range(1, 10):
        for j in range(0, 10):
            for k in range(0, 10):
                palins.append(int(f'{i}{j}{k}{k}{j}{i}'))
    n = int(input())
    for i in range(n):
        a = int(input())
        d = 2000000000
        ans = -1
        for p in palins:
            if abs(p - a) < d:
                d = abs(p - a)
                ans = p
        print(ans)