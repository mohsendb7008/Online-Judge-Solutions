# Primary Register

if __name__ == '__main__':
    cap = [2, 3, 5, 7, 11, 13, 17, 19]
    full = [2]
    for i in range(1, 8):
        full.append(full[-1] * cap[i])
    inp = list(map(int, input().split()))
    ans = inp[0]
    for i in range(1, 8):
        ans += inp[i] * full[i-1]
    print(9699689 - ans)
