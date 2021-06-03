# Magic Trick

if __name__ == '__main__':
    s = input()
    print(1 if len(set(s)) == len(s) else 0)