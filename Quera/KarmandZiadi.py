frequency = {}
for _ in range(int(input())):
    frequency[name] = frequency.get(name := input().split()[0], 0) + 1
print(max(frequency.values()))