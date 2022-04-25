# Count the Vowels

if __name__ == '__main__':
    print(len(list(filter(lambda x: x in "aeoui", input().lower()))))