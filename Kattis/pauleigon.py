# Paul Eigon

if __name__ == '__main__':
    N, P, Q = map(int, input().split())
    print('paul' if ((P + Q) // N) % 2 == 0 else 'opponent')