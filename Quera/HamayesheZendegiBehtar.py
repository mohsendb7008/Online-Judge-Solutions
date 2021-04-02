r, c = map(int, input().split())
print(' '.join(('Right' if c <= 10 else 'Left', str(11-r), str(c) if c <= 10 else str(21-c))))