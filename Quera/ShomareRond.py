from collections import Counter

def solve(s):
    for v in Counter(s).values():
        if v >= 4:
            return True
    for i in range(6):
        if s[i] == s[i+1] == s[i+2]:
            return True
    palindrom = True
    for i in range(4):
        if s[i] != s[7-i]:
            palindrom = False
            break
    return palindrom

for i in range(int(input())):
    print('Ronde!' if solve(input()) else 'Rond Nist')