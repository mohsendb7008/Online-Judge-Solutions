# Odd Binomial Coefficients

n = None
dp = {}

def cdp(i: int, k: int, b: bool):
    global n
    if (i, k, b) in dp:
        return dp[(i, k, b)]
    if i == len(n):
        dp[(i, k, b)] = 0 if b else 2 ** k
        return dp[(i, k, b)]
    if not b:
        dp[(i, k, b)] = cdp(i+1, k+1, b) + cdp(i+1, k, b)
        return dp[(i, k, b)]
    if n[i] == '0':
        dp[(i, k, b)] = cdp(i+1, k, b)
        return dp[(i, k, b)]
    dp[(i, k, b)] = cdp(i+1, k+1, b) + cdp(i+1, k, not b)
    return dp[(i, k, b)]

if __name__ == '__main__':
    n = bin(int(input()))[2:]
    print(cdp(0, 0, True))
