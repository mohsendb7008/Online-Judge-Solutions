import re

def to_number(s):
    ans = 26 ** len(s) // 25
    exp = 1
    for i in reversed(s):
        ans += (ord(i) - ord('A')) * exp
        exp *= 26
    return ans

def to_alphabet(s):
    aa = [0, 1, 27, 703, 18279, 475255, 12356631]
    for l, v in reversed(list(enumerate(aa))):
        if s >= v:
            s -= v
            ans = []
            for i in range(l):
                ans.append(chr(ord('A') + s % 26))
                s //= 26
            return ''.join(reversed(ans))

if __name__ == '__main__':
    for _ in range(int(input())):
        s = input()
        if re.findall(r'R[\d]+C[\d]+', s):
            r, c = tuple(re.findall(r'[\d]+', s))
            print(f'{to_alphabet(int(c))}{r}')
        else:
            r = re.findall(r'[\d]+', s)[0]
            c = re.findall(r'[A-z]+', s)[0]
            print(f'R{r}C{to_number(c)}')