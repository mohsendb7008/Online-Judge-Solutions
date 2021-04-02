# Fifty Shades of Pink

if __name__ == '__main__':
    n, ans = int(input()), 0
    for i in range(n):
        line = input().lower()
        if line.find('pink') != -1 or line.find('rose') != -1:
            ans += 1
    print(ans if ans else 'I must watch Star Wars with my daughter')
