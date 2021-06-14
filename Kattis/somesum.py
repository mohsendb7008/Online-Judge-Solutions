# Some Sum

if __name__ == '__main__':
    n = int(input())
    if n % 2 == 0:
        print('Even' if (n // 2) % 2 == 0 else 'Odd')
    else:
        print('Either')