n = int(input())
raw = [input().split() for _ in range(n)]
pro = [(int(b), a) for (a, b) in raw]
pro.sort()
print(pro[-1][1])