# Troll Hunt
a, b, c = map(int, input().split())
print((a-1) // (b // c) + (1 if (a-1) % (b // c) != 0 else 0))