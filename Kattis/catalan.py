# Catalan Numbers

cat = [1]

if __name__ == '__main__':
    for m in range(1, 5001):
        cat.append(((4 * m - 2) * cat[m-1]) // (m + 1))
    q = int(input())
    for i in range(q):
        print(cat[int(input())])