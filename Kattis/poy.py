# Pot
n = int(input())
ans = 0
for i in range(n):
    x = input()
    ans += int(x[:-1]) ** int(x[-1])
print(ans)