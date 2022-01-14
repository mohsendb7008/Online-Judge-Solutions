# Cut in Line

if __name__ == '__main__':
    line = [input() for _ in range(int(input()))]
    for _ in range(int(input())):
        command = input()
        if command.startswith('cut'):
            _, a, b = command.split()
            line.insert(line.index(b), a)
        elif command.startswith('leave'):
            _, a = command.split()
            line.remove(a) 
    print('\n'.join(line))