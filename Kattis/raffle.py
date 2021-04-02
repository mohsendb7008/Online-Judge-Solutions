# Fleecing the Raffle

if __name__ == "__main__":
    n, p = map(int, input().split())
    f = p / (n + 1)
    m = 2
    while True:
        g = (f * m * (n + m - p)) / ((m - 1) * (n + m))
        if g < f:
            break
        f = g
        m += 1
    print("%.10f" % f)