# Quality-Adjusted Life-Year

n = int(input())
ans = 0.0
for i in range(n):
    u, v = map(float, input().split())
    ans += u * v
print('%.3f' % ans)