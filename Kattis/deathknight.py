# Death Knight Hero

if __name__ == '__main__':
    n, ans = int(input()), 0
    for i in range(n):
        if input().find('CD') == -1:
            ans += 1
    print(ans)

