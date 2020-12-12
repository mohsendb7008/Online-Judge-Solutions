# Quite a Problem

if __name__ == '__main__':
    while True:
        try:
            line = input().lower()
        except EOFError:
            break
        print('no' if line.find('problem') == -1 else 'yes')

