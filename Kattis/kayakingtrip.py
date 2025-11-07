n = int(input())
cost = [[0]*(n+1) for _ in range(n+1)]
for i in range(1, n):
    vals = list(map(int, input().split()))
    for j, v in enumerate(vals, start=i+1):
        cost[i][j] = v

dp = [float('inf')] * (n+1)
prev = [-1] * (n+1)
dp[1] = 0

for i in range(2, n+1):
    for j in range(1, i):
        if dp[j] + cost[j][i] < dp[i]:
            dp[i] = dp[j] + cost[j][i]
            prev[i] = j

path = []
cur = n
while cur != -1:
    path.append(cur)
    cur = prev[cur]
path.reverse()

print(*path)
print(dp[n])
