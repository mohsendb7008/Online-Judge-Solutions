# Homework
print(sum(map(lambda x: 1 if x.isdigit() else int(x.split('-')[1]) - int(x.split('-')[0]) + 1, input().split(';'))))