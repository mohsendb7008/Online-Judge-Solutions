
# Criss-Cross

import sys
from fractions import Fraction as F

def dot(v, w):
    return v[0] * w[0] + v[1] * w[1] + v[2] * w[2]

def crossproduct(u, v):
    return (u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2], u[0] * v[1] - u[1] * v[0])

def signum(x): 
    return (x > 0) - (x < 0)

def isleft((x0, y0, w0), (x1, y1, w1)):
    return ((x0 * w1 - w0 * x1) * signum(w0 * w1))

def isbelow((x0, y0, w0), (x1, y1, w1)):
    return ((y0 * w1 - w0 * y1) * signum(w0 * w1))

def isCCW(p0, p1, p2):
    return dot(crossproduct(p0, p1), p2)

def inBounds(q0, q1, p):
    a = isleft(q0, p)
    b = isleft(p, q1)
    if a * b < 0:
        return False
    a = isbelow(q0, p)
    b = isbelow(p, q1)
    return a * b >= 0

def pointOnSegment(p0, p1, q):
    return inBounds(p0, p1, q) and isCCW(p0, p1, q) == 0 

n = int(raw_input())
linesegments = []
lines = []
for _ in range(n):
    x0, y0, x1, y1 = map(int, raw_input().split())
    p, q = (x0, y0, 1), (x1, y1, 1)
    linesegments.append((p, q))
    lines.append(crossproduct(p, q))

points = set()
for i, (p, q) in enumerate(linesegments):
    for j in range(i+1, n):
        r, s = linesegments[j]
        x, y, w = crossproduct(lines[i], lines[j])
        if w == 0:
            p1, p2, q1, q2 = p, q, r, s
            if (p1 == q1 and p2 == q2) or (p1 == q2 and p2 == q1):
                print -1
                sys.exit(0)
            elif p1 == q1 or p1 == q2 or p2 == q1 or p2 == q2:
                if p1 == q1:
                    if pointOnSegment(p2, q2, p1):
                        points.add(p1)
                    else:
                        print -1
                        sys.exit(0)
                elif p1 == q2:
                    if pointOnSegment(p2, q1, p1):
                        points.add(p1)
                    else:
                        print -1
                        sys.exit(0)
                elif p2 == q1:
                    if pointOnSegment(p1, q2, p2):
                        points.add(p2)
                    else:
                        print -1
                        sys.exit(0)
                elif p2 == q2:
                    if pointOnSegment(p1, q1, p2):
                        points.add(p2)
                    else:
                        print -1
                        sys.exit(0)
            elif pointOnSegment(p1, p2, q1) or pointOnSegment(p1, p2, q2) or pointOnSegment(q1, q2, p1) or pointOnSegment(q1, q2, p2):
                print -1
                sys.exit(0)
        if w != 0 and pointOnSegment(p, q, (x, y, w)) and pointOnSegment(r, s, (x, y, w)):
            points.add((F(x, w), F(y, w)))
print len(points)
