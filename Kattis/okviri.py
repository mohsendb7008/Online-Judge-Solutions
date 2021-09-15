# Okviri

if __name__ == '__main__':
    lines = [['.'], ['.'], ['#'], ['.'], ['.']]
    s = input()
    for i, c in enumerate(s):
        m = '*' if i % 3 == 2 else '#'
        lines[0].extend(['.', m, '.', '.'])
        lines[1].extend([m, '.', m, '.'])
        lines[2].extend(['.', c, '.', '*' if i + 1 < len(s) and i % 3 == 1 else m])
        lines[3].extend([m, '.', m, '.'])
        lines[4].extend(['.', m, '.', '.'])
    for line in lines:
        print(''.join(line))