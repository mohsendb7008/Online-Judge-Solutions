# Methodic Multiplication

if __name__ == '__main__':
    a, b = input(), input()
    if a == '0' or b == '0':
        print('0')
    else:
        s = a.count('S') * b.count('S')
        print('S(' * s + '0' + ')' * s)
