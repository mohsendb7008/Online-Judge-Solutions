import os

def explore(t, path):
    ans = {}
    for a, b, c in os.walk(path):
        k = len(list(filter(lambda x: x.lower().endswith(f'.{t.lower()}'), c)))
        if k:
            ans[a] = k
    return ans