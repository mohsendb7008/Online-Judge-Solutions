if __name__ == '__main__':
    while True:
        a = int(input())
        if a == -1:
            break
        if a < 10:
            print(f'1{a}')
            continue
        ans = []
        while a > 1:
            found = False
            i = 9
            while i > 1:
                if a % i == 0:
                    ans += f'{i}'
                    a //= i
                    found = True
                    break
                i -= 1
            if not found:
                break
        ans.reverse()
        print(''.join(ans) if a == 1 else 'There is no such number.')