def c(a, b):
    return a // b + (1 if a % b > 0 else 0)

print(c(min(int(input()), int(input())), max(int(input()), int(input()))))