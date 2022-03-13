# Parket

from math import sqrt

if __name__ == '__main__':
    R, B = map(int, input().split())
    xy = R + B
    xpy = (xy + 4 - B) // 2
    delta = int(sqrt(xpy ** 2 - 4 * xy))
    print((xpy + delta) // 2, (xpy - delta) // 2)
