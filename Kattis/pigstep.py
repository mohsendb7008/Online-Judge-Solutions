from sys import stdout

def ask(l, r):
    print(f"ASK {l} {r}")
    stdout.flush()
    return input().split()

def guess(s, a):
    print(f"GUESS {s} {a}")
    stdout.flush()

def solve(l, r):
    split = False
    while l < r and not split:
        mid = (l + r) // 2
        s, a = ask(l, mid)
        if s == a:
            if s == 'yes':
                r = mid
            elif s == 'no':
                l = mid+1
        else:
            if s == 'yes':
                ls, rs = l, mid
                la, ra = mid+1, r
            elif s == 'no':
                ls, rs = mid+1, r
                la, ra = l, mid
            split = True
    if not split:
        guess(l, l)
        return
    while ls < rs or la < ra:
        if rs < la:
            ms = (ls + rs + 1) // 2
            ma = (la + ra) // 2
            s, a = ask(ms, ma)
            if s == 'yes':
                ls = ms
            elif s == 'no':
                rs = ms-1
            if a == 'yes':
                ra = ma
            elif a == 'no':
                la = ma+1
        else:
            ms = (ls + rs) // 2
            ma = (la + ra + 1) // 2
            s, a = ask(ma, ms)
            if s == 'yes':
                rs = ms
            elif s == 'no':
                ls = ms+1
            if a == 'yes':
                la = ma
            elif a == 'no':
                ra = ma-1
    guess(ls, la)

if __name__ == '__main__':
    solve(1, 500)