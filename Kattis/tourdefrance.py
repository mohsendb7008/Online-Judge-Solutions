from fractions import Fraction as frac

# Tour de France

if __name__ == '__main__':
    while True:
        line = input()
        if line.strip() == '0':
            break
        f, r = map(int, line.split())
        fl = list(map(int, input().split()))
        fr = list(map(int, input().split()))
        ratios = []
        for n in fr:
            for m in fl:
                ratios.append(frac(n, m))
        ratios.sort()
        ans = frac(0, 1)
        for i in range(len(ratios) - 1):
            ans = max(ans, ratios[i + 1] / ratios[i])
        print(f'{ans.numerator / ans.denominator:.2f}')