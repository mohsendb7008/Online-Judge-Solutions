# Closing the Loop

if __name__ == '__main__':
    for _ in range(int(input())):
        r, b = [], []
        input()
        for l in input().split():
            if l.endswith('R'):
                r.append(int(l[:-1]))
            elif l.endswith('B'):
                b.append(int(l[:-1]))
        r.sort()
        b.sort()
        r.reverse()
        b.reverse()
        ans = 0
        for i, j in zip(r, b):
            ans += i + j - 2
        print(f'Case #{_ + 1}: {ans}')
