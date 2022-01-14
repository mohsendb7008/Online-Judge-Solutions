# Access Denied

import re
import sys

def hear(say):
    print(say)
    sys.stdout.flush()
    line = input()
    if line.strip() == 'ACCESS GRANTED':
        return -1
    return int(re.findall(r'\d+', line)[0])

def guessLength():
    i = 1
    while True:
        time = hear('a' * i)
        if time == -1:
            sys.exit(0)
        elif time != 5:
            return i
        i += 1
    assert(True == False)

ALPHABET = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789'

if __name__ == '__main__':
    length = guessLength()
    ans = [0 for i in range(length)]
    while True:
        time = hear(''.join(map(lambda x: ALPHABET[x], ans)))
        if time == -1:
            sys.exit(0)
        ans[(time - 14) // 9] += 1
    assert(True == False)

