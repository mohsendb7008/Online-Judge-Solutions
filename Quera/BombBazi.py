def f(x):
    return int(x)-1
def g(x):
    return ' '.join(x)
adjR = [0, 0, 1, -1, 1, 1, -1, -1]
adjC = [1, -1, 0, 0, 1, -1, 1, -1]
n, m = map(int, input().split())
k = int(input())
ans = [['0']*m for _ in range(n)]
for _ in range(k):
    x, y = map(f, input().split())
    ans[x][y] = '*'
    for r in range(8):
        nx, ny = x+adjR[r], y+adjC[r]
        if nx >= 0 and nx < n and ny >= 0 and ny < m and ans[nx][ny] != '*':
            ans[nx][ny] = str(int(ans[nx][ny])+1)
print('\n'.join(map(g, ans)))