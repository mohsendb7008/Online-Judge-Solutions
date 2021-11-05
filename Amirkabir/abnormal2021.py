a, b = map(int, input().split())
l = [a] * b + [b] * a
ans = 0
for i in range(len(l)):
    if i % 2 == 0:
        ans += l[i]
    else:
        ans -= l[i]
print(ans)