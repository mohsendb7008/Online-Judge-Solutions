# T9 Spelling

keyboard = {
    'a': '2',
    'b': '22',
    'c': '222',
    'd': '3',
    'e': '33',
    'f': '333',
    'g': '4',
    'h': '44',
    'i': '444',
    'j': '5',
    'k': '55',
    'l': '555',
    'm': '6',
    'n': '66',
    'o': '666',
    'p': '7',
    'q': '77',
    'r': '777',
    's': '7777',
    't': '8',
    'u': '88',
    'v': '888',
    'w': '9',
    'x': '99',
    'y': '999',
    'z': '9999',
    ' ': '0'
}

if __name__ == '__main__':
    for i in range(int(input())):
        data = list(map(lambda x: keyboard[x], input()))
        print(f'Case #{i+1}:', end=' ')
        for i in range(len(data)):
            if i > 0 and data[i-1][0] == data[i][0]:
                print(end=' ')
            print(data[i], end='')
        print()