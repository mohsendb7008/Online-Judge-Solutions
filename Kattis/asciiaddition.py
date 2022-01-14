# ASCII Addition

d2a = {
    '0': 'xxxxxx...xx...xx...xx...xx...xxxxxx',
    '1': '....x....x....x....x....x....x....x',
    '2': 'xxxxx....x....xxxxxxx....x....xxxxx',
    '3': 'xxxxx....x....xxxxxx....x....xxxxxx',
    '4': 'x...xx...xx...xxxxxx....x....x....x',
    '5': 'xxxxxx....x....xxxxx....x....xxxxxx',
    '6': 'xxxxxx....x....xxxxxx...xx...xxxxxx',
    '7': 'xxxxx....x....x....x....x....x....x',
    '8': 'xxxxxx...xx...xxxxxxx...xx...xxxxxx',
    '9': 'xxxxxx...xx...xxxxxx....x....xxxxxx',
    '+': '.......x....x..xxxxx..x....x.......'
}

a2d = {}

if __name__ == '__main__':
    for d, a in d2a.items():
        a2d[a] = d
    first_line = input() + '.'
    n = len(first_line) // 6
    digits = [[first_line[6*i : 6*i + 5]] for i in range(n)]
    for _ in range(6):
        line = input() + '.'
        for i in range(n):
            digits[i].append(line[6*i : 6*i + 5])
    result = str(eval(''.join(map(lambda digit: a2d[''.join(digit)], digits))))
    ans = [[] for _ in range(7)]
    for j, ch in enumerate(result):
        flat = d2a[ch]
        for i in range(7):
            ans[i].append(flat[5*i : 5*i + 5] + ('.' if j != len(result) - 1 else ''))
    for line in ans:
        print(''.join(line))
    