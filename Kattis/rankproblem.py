n, m = map(int, input().split())
teams = [f"T{i+1}" for i in range(n)]

for _ in range(m):
    a, b = input().split()
    pos_a = teams.index(a)
    pos_b = teams.index(b)

    if pos_a > pos_b:
        teams.insert(pos_a, teams.pop(pos_b))

print(*teams)
