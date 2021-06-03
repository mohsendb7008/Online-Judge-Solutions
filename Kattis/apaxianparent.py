# Honour Thy (Apaxian) Parent

if __name__ == '__main__':
    Y, P = input().split()
    if Y.endswith('ex'):
        print(Y + P)
    elif Y.endswith('e'):
        print(Y + 'x' + P)
    elif Y.endswith('a') or Y.endswith('i') or Y.endswith('o') or Y.endswith('u'):
        print(Y[:-1] + 'ex' + P)
    else:
        print(Y + 'ex' + P)