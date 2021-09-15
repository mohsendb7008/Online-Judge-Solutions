from math import sqrt
from math import atan2
from math import pi

# Billiard

if __name__ == "__main__":
    while True:
        a, b, s, m, n = map(float, input().split())
        if a == 0 and b == 0 and s == 0 and m == 0 and n == 0:
            break
        dis = sqrt((n * b) ** 2 + (m * a) ** 2)
        angle = atan2(n * b, m * a)
        print("%.2f %.2f" %((angle * 180) / pi , dis / s))