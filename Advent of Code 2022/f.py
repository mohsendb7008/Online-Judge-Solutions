s = input()
print(list(filter(lambda i: len(set(s[i:i+4])) == 4, range(len(s))))[0] + 4)