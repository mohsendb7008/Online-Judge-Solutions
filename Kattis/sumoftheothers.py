# Sum of the Others

if __name__ == '__main__':
    while True:
        try:
            line = input()
            numbers = list(map(int, line.split()))
            all_sum = sum(numbers)
            for i in range(len(numbers)):
                if all_sum - numbers[i] == numbers[i]:
                    print(numbers[i])
                    break
        except EOFError:
            break