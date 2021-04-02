# Above Average
for _ in range(int(input())):
    l = list(map(int, input().split()))
    n = l.pop(0)
    print(f'{len(list(filter(lambda x: x>sum(l)/n, l)))*100/n:.3f}%')