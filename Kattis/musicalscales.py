# Musical Scales

notes = ['A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#']

def gen_scale(i):
    ans = [notes[i]]
    increments = [2, 2, 1, 2, 2, 2, 1]
    for increment in increments:
        i = (i + increment) % len(notes)
        ans.append(notes[i])
    return set(ans)

if __name__ == '__main__':
    input()
    song = set(input().split())
    ans = []
    for i in range(len(notes)):
        if not song - gen_scale(i):
            ans.append(notes[i])
    if ans:
        print(' '.join(ans))
    else:
        print('none')