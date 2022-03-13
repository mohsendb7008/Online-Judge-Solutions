# Espresso!

if __name__ == '__main__':
    n, s = map(int, input().split())
    cap, ans = s, 0
    for i in range(n):
        coffee = input()
        if coffee.endswith('L'):
            coffee = int(coffee[:-1]) + 1
        else:
            coffee = int(coffee)
        if cap >= coffee:
            cap -= coffee
        else:
            ans += 1
            cap = s - coffee
    print(ans)
