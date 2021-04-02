def solve(a):
    return len(list(filter(lambda line: not line.strip().startswith('#') and not line.strip() == '', open(a).readlines())))