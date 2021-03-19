from collections import Counter

# Odd Man Out

if __name__ == '__main__':
    for i in range(1, int(input()) + 1):
        input()
        print(f'Case #{i}: {next(filter(lambda pair: pair[1] == 1, Counter(input().split()).items()))[0]}')