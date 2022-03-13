# Time Travelling Temperatures

if __name__ == '__main__':
    X, Y = map(int, input().split())
    if Y == 1 and X == 0:
        print('ALL GOOD')
    elif Y == 1:
        print('IMPOSSIBLE')
    else:
        print(X / (1 - Y))