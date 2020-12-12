# Batmanacci

fib = [0, 1, 1]

if __name__ == '__main__':
    n, k = map(int, input().split())
    for i in range(3, n+1):
        fib.append(fib[i-2] + fib[i-1])
    while n > 2:
        if k <= fib[n-2]:
            n -= 2
        else:
            k -= fib[n-2]
            n -= 1
    print('N' if n == 1 else 'A')
