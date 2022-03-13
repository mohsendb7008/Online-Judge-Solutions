# Babylonian Numbers

if __name__ == '__main__':
    for _ in range(int(input())):
        ans = 0
        for i, x in enumerate(reversed(input().split(','))):
            if x:
                ans += int(x) * 60 ** i
        print(ans)
