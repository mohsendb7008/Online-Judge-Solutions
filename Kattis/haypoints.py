# Hay Points

if __name__ == '__main__':
    m, _ = map(int, input().split())
    dic = dict([input().split() for i in range(m)])
    ans = 0
    while True:
        try:
            line = input()
            if line == '.':
                print(ans)
                ans = 0
            else:
                ans += sum(list(map(lambda x: int(dic.get(x, '0')), line.split())))
        except EOFError:
            break
