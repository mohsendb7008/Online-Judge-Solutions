# Bluetooth

ru, lu, rd, ld = [], [], [], []

belong = {
    '1+': ru,
    '2+': ru,
    '3+': ru,
    '4+': ru,
    '5+': ru,
    '6+': ru,
    '7+': ru,
    '8+': ru,
    '+1': lu,
    '+2': lu,
    '+3': lu,
    '+4': lu,
    '+5': lu,
    '+6': lu,
    '+7': lu,
    '+8': lu,
    '1-': rd,
    '2-': rd,
    '3-': rd,
    '4-': rd,
    '5-': rd,
    '6-': rd,
    '7-': rd,
    '8-': rd,
    '-1': ld,
    '-2': ld,
    '-3': ld,
    '-4': ld,
    '-5': ld,
    '-6': ld,
    '-7': ld,
    '-8': ld,
}

if __name__ == '__main__':
    for c, k in belong.items():
        k.append(c)
    n = int(input())
    for i in range(n):
        a, b = input().split()
        if b == 'b':
            belong[a].clear()
        elif b == 'm':
            try:
                belong[a].remove(a)
            except e:
                pass
    if ru and rd:
        print(1)
    elif lu and ld:
        print(0)
    else:
        print(2)
