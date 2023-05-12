S = [0, 0]
T = [0, 0]

def adjacent():
    return abs(S[0] - T[0]) <= 1 and abs(S[1] - T[1]) <= 1

def sign(d):
    if d > 0:
        return 1
    elif d < 0:
        return -1
    return 0

visited = {(0, 0)}

while True:
    try:
        c, a = input().split()
        for _ in range(int(a)):
            if c == 'R':
                S[1] += 1
            elif c == 'L':
                S[1] -= 1
            elif c == 'U':
                S[0] -= 1
            elif c == 'D':
                S[0] += 1

            if not adjacent():
                T[0] += sign(S[0] - T[0])
                T[1] += sign(S[1] - T[1])
                visited.add((T[0], T[1]))
    except EOFError:
        break

print(len(visited))