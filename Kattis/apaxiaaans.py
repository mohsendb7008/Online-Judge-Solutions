# Apaxiaaaaaaaaaaaans!

if __name__ == '__main__':
    apx = []
    for c in input():
        if apx and apx[-1] == c:
            continue
        apx.append(c)
    print(''.join(apx))