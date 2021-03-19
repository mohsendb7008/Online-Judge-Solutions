# A1 Paper

def solve(i, need, h, w):
    if i >= n:
        return None
    if need <= a[i]:
        return (need // 2) * h
    x = solve(i+1, 2 * (need - a[i]), w, h / 2)
    if x != None:
        return (need // 2) * h + x
    return None

n, a = int(input())-1, list(map(int, input().split()))
x = solve(0, 2, 2 ** (-3 / 4), 2 ** (-5 / 4))
print(f'{x:.11f}' if x != None else 'impossible')