# Tai's formula

if __name__ == '__main__':
    n = int(input())
    glucose = [tuple(map(float, input().split())) for _ in range(n)]
    ans = 0
    for i in range(n-1):
        a, b, h = glucose[i][1], glucose[i+1][1], glucose[i+1][0] - glucose[i][0]
        ans += min(a, b) * h + abs(b - a) * h / 2
    print(ans / 1000) 