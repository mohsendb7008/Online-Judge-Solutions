# Array of Discord

if __name__ == '__main__':
    n = int(input())
    a = input().split()
    for i in range(n):
        for j in range(len(a[i])):
            for c in '0123456789':
                if len(a[i]) > 1 and j == 0 and c == '0':
                    continue
                b = a.copy()
                b[i] = b[i][:j] + c + b[i][j+1:]
                c = [(int(b[k]), k) for k in range(n)]
                c.sort()
                if c[i][1] != i:
                    print(' '.join(b))
                    exit(0)
    print('impossible')