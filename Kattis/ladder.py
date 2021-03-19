# Ladder
from math import radians, sin
h, v = map(int, input().split())
print(round(h/sin(radians(v))+0.5))