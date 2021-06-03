# Heir's Dilemma

from collections import Counter

def has_zero(s: str):
    return s.find('0') != -1

def different_digits(s: str):
    return list(filter(lambda x: x > 1, Counter(s).values())) == []

def divisble_by_digits(s: str):
    return list(filter(lambda x: int(s) % int(x) > 0, s)) == []

if __name__ == '__main__':
    L, H = map(int, input().split())
    ans = 0
    for candidate in range(L, H + 1):
        c = str(candidate)
        if not has_zero(c) and different_digits(c) and divisble_by_digits(c):
            ans += 1
    print(ans)