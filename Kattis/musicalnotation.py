# Musical Notation

if __name__ == '__main__':
    input()
    a = input().split()
    def f(a):
        b = []
        for d in a:
            if len(d) == 1:
                b.append(d)
            else:
                b.extend([d[:1] for _ in range(int(d[1:]))])
            b.append('X')
        b.pop()
        return b
    a = f(a)
    n = len(a)
    music = {
        'G': [' ' for _ in range(n)],
        'F': ['-' for _ in range(n)],
        'E': [' ' for _ in range(n)],
        'D': ['-' for _ in range(n)],
        'C': [' ' for _ in range(n)],
        'B': ['-' for _ in range(n)],
        'A': [' ' for _ in range(n)],
        'g': ['-' for _ in range(n)],
        'f': [' ' for _ in range(n)],
        'e': ['-' for _ in range(n)],
        'd': [' ' for _ in range(n)],
        'c': [' ' for _ in range(n)],
        'b': [' ' for _ in range(n)],
        'a': ['-' for _ in range(n)]
    }
    for i in range(n):
        if a[i] != 'X':
            music[a[i]][i] = '*'
    for k, v in music.items():
        print(f'{k}: {"".join(v)}')