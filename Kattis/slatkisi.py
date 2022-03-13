# Slatkisi

if __name__ == '__main__':
    C, K = map(int, input().split())
    print(round(C / (10 ** K) + 1e-9) * (10 ** K))