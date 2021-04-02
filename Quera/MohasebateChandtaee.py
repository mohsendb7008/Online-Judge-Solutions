def calc(x):
    return sum(x)/len(x), sorted(x)[len(x)//2] if len(x) % 2 == 1 else (sorted(x)[len(x)//2-1]+sorted(x)[len(x)//2])/2, max(x)