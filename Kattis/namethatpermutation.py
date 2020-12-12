# Name That Permutation

fact = [1]

if __name__ == '__main__':
    for i in range(1, 51):
        fact.append(fact[i-1] * i)
    while True:
        try:
            n, k = map(int, input().split())
            ans = [i + 1 for i in range(n)]
            while True:
                if n == 1:
                    print(ans[0])
                    break
                print(ans.pop(k // fact[n-1]), end=' ')
                k %= fact[n-1]
                n -= 1
        except EOFError:
            break