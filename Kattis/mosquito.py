# Mosquito Multiplication

if __name__ == '__main__':
    while True:
        try:
            M, P, L, E, R, S, N = map(int, input().split())
            for _ in range(N):
                NEW_L = M * E
                NEW_P = L // R
                NEW_M = P // S
                M, P, L = NEW_M, NEW_P, NEW_L
            print(M)
        except EOFError:
            break