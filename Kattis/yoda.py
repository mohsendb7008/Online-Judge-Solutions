# Yoda

if __name__ == '__main__':
    a, b = input(), input()
    z = max(len(a), len(b))
    aa, bb = [], []
    for s, t in zip(a.zfill(z), b.zfill(z)):
        if s < t:
            bb.append(t)
        elif s > t:
            aa.append(s)
        else:
            aa.append(s)
            bb.append(t)
    print(int(''.join(aa)) if aa else 'YODA')
    print(int(''.join(bb)) if bb else 'YODA')