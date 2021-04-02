first = True
memo = {}

def comb(n, k):
    if n < k:
        return 0
    global first, memo
    if first:
        first = False
        for i in range(21):
            for j in range(i+1):
                memo[(i, j)] = 1 if j == 0 or i == j else memo[(i-1, j)] + memo[(i-1, j-1)]
    return memo[(n, k)]