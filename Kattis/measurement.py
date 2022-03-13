# Imperial Measurement

m = {
    'th': 1,
    'in': 1000,
    'ft': 12 * 1000,
    'yd': 3 * 12 * 1000,
    'ch': 22 * 3 * 12 * 1000,
    'fur': 10 * 22 * 3 * 12 * 1000,
    'mi': 8 * 10 * 22 * 3 * 12 * 1000,
    'lea': 3 * 8 * 10 * 22 * 3 * 12 * 1000,
}

t = {
    'thou': 'th',
    'inch': 'in',
    'foot': 'ft',
    'yard': 'yd',
    'chain': 'ch',
    'furlong': 'fur',
    'mile': 'mi',
    'league': 'lea'
}

if __name__ == '__main__':
    n, a, _, b = input().split()
    n = int(n)
    if len(a) > 3:
        a = t[a]
    if len(b) > 3:
        b = t[b]
    print(n * m[a] / m[b])