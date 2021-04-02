transformations = ['(((', '(()', '()(', '())', ')((', ')()', '))(', ')))']

def regular(string):
    opened = 0
    for c in string:
        if c == '(':
            opened += 1
        elif opened > 0:
            opened -= 1
        else:
            return False
    return opened == 0

def solve(string):
    for t in transformations:
        if regular(string.replace('A', t[0]).replace('B', t[1]).replace('C', t[2])):
            return True
    return False

if __name__ == '__main__':
    for i in range(int(input())):
        print('YES' if solve(input()) else 'NO')