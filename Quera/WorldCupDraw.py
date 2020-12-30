teams = ["Russia", "Germany", "Brazil", "Portugal",
         "Argentina", "Belgium", "Poland", "France",
         "Spain", "Peru", "Switzerland", "England",
         "Colombia", "Mexico", "Uruguay", "Croatia",
         "Denmark", "Iceland", "Costa Rica", "Sweden",
         "Tunisia", "Egypt", "Senegal", "Iran",
         "Serbia", "Nigeria", "Australia", "Japan",
         "Morocco", "Panama", "South Korea", "Saudi Arabia"]

scores = [65, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 16, 17, 18,
          19, 21, 22, 25, 28, 30, 32, 34, 38, 41, 43, 44, 48, 49, 62, 63]

# UEFA: 0, CONMEBOL: 1, CONCACAF: 2, CAF: 3, AFC: 4
tags = [0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 2, 1, 0, 
        0, 0, 2, 0, 3, 3, 3, 4, 0, 3, 4, 4, 3, 2, 4, 4]

perm, perms = [], []

def generate(i):
    if i == 8:
        perms.append(perm.copy())
        return
    for j in range(8):
        if j not in perm:
            perm.append(j)
            generate(i + 1)
            perm.pop()
    
team_id = {}

if __name__ == '__main__':
    generate(0)
    cnt = 0
    for name in teams:
        team_id[name] = cnt
        cnt += 1
    while True:
        line = input()
        if line == "End":
            break
        pots = [[team_id[name.strip()] for name in line.split(',')]]
        for i in range(3):
            pots.append([team_id[name.strip()] for name in input().split(',')])
        group_tags = [{} for i in range(8)]
        group_scores = [0 for i in range(8)]
        for pot in pots:
            for perm in perms:
                ok = True
                for i in range(8):
                    u, v = pot[i], perm[i]
                    if tags[u] == 0:
                        if group_tags[v].get(0, 0) >= 2:
                            ok = False
                            break
                    elif group_tags[v].get(tags[u], 0) >= 1:
                        ok = False
                        break
                if ok:
                    for i in range(8):
                        u, v = pot[i], perm[i]
                        if tags[u] in group_tags[v]:
                            group_tags[v][tags[u]] += 1
                        else:
                            group_tags[v][tags[u]] = 1
                        group_scores[v] += scores[u]
                    break
        ans = [(group_scores[i], chr(ord('A') + i)) for i in range(8)]
        ans.sort()
        for a in ans:
            print(f'{a[1]} {a[0]}')

        