# Poker Hand

if __name__ == "__main__":
    s = input().split()
    d = {}
    for ss in s:
        if ss[0] in d:
            d[ss[0]] += 1
        else:
            d[ss[0]] = 1
    print(max(d.values()))
