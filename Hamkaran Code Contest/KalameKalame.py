if __name__ == '__main__':
    name = input()
    print(2 ** len(list(filter(lambda x: x in ['a', 'e', 'i', 'o', 'u'], name))))