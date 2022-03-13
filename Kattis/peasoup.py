# Pea Soup and Pancakes

import sys

if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        name = input()
        menu = set()
        for _ in range(n):
            menu.add(input())
        if 'pea soup' in menu and 'pancakes' in menu:
            print(name)
            sys.exit(0)
    print('Anywhere is fine I guess')