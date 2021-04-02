# Alphabet Spam

if __name__ == '__main__':
    line = input()
    x, y, z = len(list(filter(lambda x: x == '_', line))), len(list(filter(lambda x: x.islower(), line))), len(list(filter(lambda x: x.isupper(), line)))
    print(x / len(line))
    print(y / len(line))
    print(z / len(line))
    print(1 - (x + y + z) / len(line))