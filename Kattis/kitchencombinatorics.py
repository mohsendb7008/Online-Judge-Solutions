# Kitchen Combinatorics

if __name__ == "__main__":
    r, s, m, d, n = map(int, input().split())
    ing = list(map(int, input().split()))
    dishes = []
    for i in range(s + m + d):
        dishes.append(list(map(int, input().split()[1:])))
    forbid = set()
    for i in range(n):
        u, v = map(int, input().split())
        forbid.add((min(u, v) - 1, max(u, v) - 1))
    ans = 0
    for i in range(s):
        for j in range(s, s + m):
            for k in range(s + m, s + m + d):
                if (i, j) not in forbid and (i, k) not in forbid and (j, k) not in forbid:
                    cur = 1
                    dish = set(dishes[i]) | set(dishes[j]) | set(dishes[k])
                    for item in dish:
                        cur *= ing[item - 1]
                    ans += cur
                    if ans > 10 ** 18:
                        print("too many")
                        exit(0)
    print(ans)