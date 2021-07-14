# Preludes

m = {
    'A#': 'Bb',
    'Bb': 'A#',
    'C#': 'Db',
    'Db': 'C#',
    'D#': 'Eb',
    'Eb': 'D#',
    'F#': 'Gb',
    'Gb': 'F#',
    'G#': 'Ab',
    'Ab': 'G#'
}

if __name__ == '__main__':
    case = 1
    while True:
        try:
            a, b = input().split()
            if a not in m:
                print(f'Case {case}: UNIQUE')
            else:
                print(f'Case {case}: {m[a]} {b}')
            case += 1
        except EOFError:
            break