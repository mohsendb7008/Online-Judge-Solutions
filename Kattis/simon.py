# Simon Says

if __name__ == '__main__':
    n = int(input())
    for i in range(n):
        line = input()
        if line.startswith('simon says '):
            print(line[11:])
        else:
            print()
