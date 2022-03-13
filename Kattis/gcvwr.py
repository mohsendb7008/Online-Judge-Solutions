# GCVWR

if __name__ == '__main__':
    G, T, N = map(int, input().split())
    print(9 * (G - T) // 10 - sum(list(map(int, input().split()))))
