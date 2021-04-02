def find_bird_index(birds: list, bird: str):
    for i in range(len(birds)):
        if birds[i] == bird:
            return i
    return -1

if __name__ == '__main__':
    n, s = map(int, input().split())
    birds = input().split()
    for _ in range(s):
        cmd = input().split()
        if cmd[0] == 'insert':
            birds.insert(int(cmd[2]), cmd[1])
        elif cmd[0] == 'depart':
            birds.pop(find_bird_index(birds, cmd[1]))
        elif cmd[0] == 'relocate':
            index = find_bird_index(birds, cmd[1])
            bird = birds.pop(index)
            birds.insert(index + int(cmd[2]), bird)
    print(' '.join(birds))
