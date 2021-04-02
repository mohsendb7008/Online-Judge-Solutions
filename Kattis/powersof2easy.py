# Powers of 2 (Easy)
if __name__ == '__main__':
    n, e = map(int, input().split())
    te = str(2 ** e)
    ans = 0
    for i in range(n + 1):
        if str(i).find(te) != -1:
            ans += 1
    print(ans)