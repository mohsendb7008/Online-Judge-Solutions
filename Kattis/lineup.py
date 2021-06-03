# Line Them Up

if __name__ == '__main__':
    n = int(input())
    l = [input() for i in range(n)]
    if l == sorted(l):
        print('INCREASING')
    elif l == list(reversed(sorted(l))):
        print('DECREASING')
    else:
        print('NEITHER')