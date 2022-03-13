# Hardware

if __name__ == '__main__':
    for _ in range(int(input())):
        street = input()
        addresses = input()
        n = int(addresses.split()[0])
        digits = {
            '0': 0,
            '1': 0,
            '2': 0,
            '3': 0,
            '4': 0,
            '5': 0,
            '6': 0,
            '7': 0,
            '8': 0,
            '9': 0
        }
        total = 0
        while n > 0:
            line = input()
            if line.startswith('+'):
                _, a, b, c = line.split()
                for i in range(int(a), int(b) + 1, int(c)):
                    for c in str(i):
                        digits[c] += 1
                        total += 1
                    n -= 1
            else:
                for c in line:
                    digits[c] += 1
                    total += 1
                n -= 1
        print(street)
        print(addresses)
        for k, v in digits.items():
            print(f'Make {v} digit {k}')
        print(f'In total {total} digit{"s" if total > 1 else ""}')
