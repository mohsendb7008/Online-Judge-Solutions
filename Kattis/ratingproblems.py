# Rating Problems

if __name__ == '__main__':
    n, k = map(int, input().split())
    ans = sum([int(input()) for _ in range(k)])
    print((ans-3*(n-k))/n, (ans+3*(n-k))/n)