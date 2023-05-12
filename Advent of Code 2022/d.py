ans = 0
while True:
    try:
        x, y = input().split(",")
        a, b = map(int, x.split("-"))
        c, d = map(int, y.split("-"))
        if (a >= c and b <= d) or (c >= a and d <= b):
            ans += 1
    except EOFError:
        break
print(ans)