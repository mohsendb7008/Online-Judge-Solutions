# Catalan Square

cat = [1]

if __name__ == '__main__':
    n = int(input())
    for m in range(1, n+2):
        cat.append(((4 * m - 2) * cat[m-1]) // (m + 1))
    print(cat[n+1])