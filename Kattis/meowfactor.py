# Meow Factor

if __name__ == '__main__':
    n, ans = int(input()), 0
    for i in range(1, n + 1):
        if i ** 9 > n :
            break
        if n % (i ** 9) == 0:
            ans = max(ans, i)
    print(ans)