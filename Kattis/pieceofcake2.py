# Piece of Cake!
n, v, h = map(int, input().split())
print(4 * max(v, n - v) * max(h, n - h))