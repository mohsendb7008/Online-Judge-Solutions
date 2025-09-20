a = input()
print(f"{len(list(filter(lambda x: x in 'aeiou', a)))} {len(list(filter(lambda x: x in 'aeiouy', a)))}")