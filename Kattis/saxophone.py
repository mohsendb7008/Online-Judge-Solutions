# Eb Alto Saxophone Player

sax = {
    'c': [2, 3, 4, 7, 8, 9, 10],
    'd': [2, 3, 4, 7, 8, 9],
    'e': [2, 3, 4, 7, 8],
    'f': [2, 3, 4, 7],
    'g': [2, 3, 4],
    'a': [2, 3],
    'b': [2],
    'C': [3],
    'D': [1, 2, 3, 4, 7, 8, 9],
    'E': [1, 2, 3, 4, 7, 8],
    'F': [1, 2, 3, 4, 7],
    'G': [1, 2, 3, 4],
    'A': [1, 2, 3],
    'B': [1, 2]
}

if __name__ == '__main__':
    for _ in range(int(input())):
        freq = [0 for _ in range(11)]
        play = []
        for c in input():
            for i in range(1, 11):
                if i not in play and i in sax[c]:
                    freq[i] += 1
            play = sax[c]
        print(' '.join(map(str, freq[1:])))
