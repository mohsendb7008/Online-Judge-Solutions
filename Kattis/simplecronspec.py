# Simple Cron Spec

def process(str, bound):
    if str == '*':
        return list(range(bound))
    res = []
    for tok in str.split(','):
        if tok.find('-') == -1:
            res.append(int(tok))
        else:
            a, b = map(int, tok.split('-'))
            res.extend(list(range(a, b + 1)))
    return res

if __name__ == '__main__':
    ans = 0
    dis = set()
    for _ in range(int(input())):
        h, m, s = input().split()
        h, m, s = process(h, 24), process(m, 60), process(s, 60)
        ans += len(h) * len(m) * len(s)
        for i in h:
            for j in m:
                for k in s:
                    dis.add(3600 * i + 60 * j + k)
    print(len(dis), ans)