from math import sqrt
from math import fabs

EPS = 1e-7

segments = []
drawing = [None for i in range(100)]
trs = [[] for i in range(10000)]
best = 0
unUsedSegments = 0

def third_point(a, b, c):
    x = (c ** 2 - b ** 2 + a ** 2) / (2 * a)
    y = sqrt(c ** 2 - x ** 2)
    return x, y

def rotate(x, y, m):
    cos2 = 1 / (m ** 2 + 1)
    cos = sqrt(cos2)
    sin = sqrt(1 - cos2)
    if m < 0:
        sin *= -1
    return x * cos - y * sin, x * sin + y * cos

def explore(first = False):
    global best
    global unUsedSegments
    if unUsedSegments < 2:
        return
    goodSegmentsThisTime = []
    for i in segments:
        if not drawing[i]:
            goodSegmentsThisTime.append(i)
    n = len(goodSegmentsThisTime)
    for i in range(n):
        b = goodSegmentsThisTime[i]
        for j in range(i + 1 if first else 0, n):
            c = goodSegmentsThisTime[j]
            if b != c:
                for a in trs[b * 100 + c]:
                    if drawing[a]:
                        A, B = drawing[a]
                        for orientation in [-1, 1]:
                            C = third_point(a, b, c)
                            C = (C[0], C[1] * orientation)
                            dy, dx = B[1] - A[1], B[0] - A[0]
                            if fabs(dx) < EPS:
                                C = -C[1], C[0]
                            else:
                                m = dy / dx
                                C = rotate(C[0], C[1], m)
                            C = (C[0] + A[0], C[1] + A[1])
                            if C[1] < 0:
                                continue
                            if C[1] > best:
                                best = C[1]
                            con1 = (min(A, C), max(A, C))
                            con2 = (min(C, B), max(C, B))
                            drawing[c] = con1
                            drawing[b] = con2
                            unUsedSegments -= 2
                            explore()
                            unUsedSegments += 2
                            drawing[b] = None
                            drawing[c] = None

def check_triangle(a, b, c):
    return a + b > c and a + c > b and b + c > a

if __name__ == '__main__':
    instance = list(map(int, input().split()))
    unUsedSegments = instance[0]
    segments.extend(instance[1:])
    for a in segments:
        for b in segments:
            for c in segments:
                if a != b and b != c and check_triangle(a, b, c):
                    trs[a * 100 + b].append(c)
    for segment in segments:
        drawing[segment] = (0, 0), (segment, 0)
        unUsedSegments -= 1
        explore(True)
        unUsedSegments += 1
        drawing[segment] = None
    print(best)