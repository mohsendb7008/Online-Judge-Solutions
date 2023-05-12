digits = {
    '2': 2,
    '1': 1,
    '0': 0,
    '-': -1,
    '=': -2
}

def convert(num):
    exp = 1
    ans = 0
    for c in reversed(num):
        ans += digits[c] * exp
        exp *= 5
    return ans

def rconvert(num):
    l = []
    while num > 0:
        digit = num % 5
        num = num // 5
        if digit == 4:
            num += 1
            l.append('-')
        elif digit == 3:
            num += 1
            l.append('=')
        else:
            l.append(str(digit))
    return ''.join(reversed(l))

total = 0

while True:
    try:
        total += convert(input())
    except KeyboardInterrupt:
        break

print(rconvert(total))