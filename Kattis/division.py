from math import log10

# Division

EPS = 1e-9

def fast_pow(a, b):
    if b == 0:
        return 1
    if b % 2 == 1:
        return a * fast_pow(a, b - 1)
    m = fast_pow(a, b // 2)
    return m * m

if __name__ == '__main__':
    while True:
        try:
            t, a, b = map(int, input().split())
            print(f'({t}^{a}-1)/({t}^{b}-1)', end=' ')
            if t == 1:
                print('is not an integer with less than 100 digits.')
            elif a < b:
                print('is not an integer with less than 100 digits.')
            elif a == b:
                print('1')
            elif a % b != 0:
                print('is not an integer with less than 100 digits.')
            elif b * log10(t) + 1 + EPS >= 100:
                print('is not an integer with less than 100 digits.')
            else:
                lgt, q, ok, seq, ans = log10(t), fast_pow(t, b), True, 1, 1
                for i in range(1, a // b):
                    if lgt * i * b + 1 + EPS >= 100:
                        ok = False
                        break
                    seq *= q
                    ans += seq
                    if len(str(ans)) >= 100:
                        ok = False
                        break
                if ok:
                    print(ans)
                else:
                    print('is not an integer with less than 100 digits.')
        except EOFError:
            break
