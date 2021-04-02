# Witchwood

if __name__ == "__main__":
    n, m, k = map(int, input().split())
    woods = [tuple(map(float, input().split())) for _ in range(m)]
    ans = 0.0
    for _ in range(n):
        temp = (ans + woods[0][0] + k * woods[0][1]) / (1 - woods[0][1])
        for i in range(1, m):
            temp = min(temp, (ans + woods[i][0] + k * woods[i][1]) / (1 - woods[i][1]))
        ans = temp
    print(ans)