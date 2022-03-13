# Calories From Fat

helper = [9, 4, 4, 4, 7]

def solve(lines):
    numerator, denominator = 0, 0
    for line in lines:
        ings = line.split()
        a, b = 0, 1
        for i in range(len(ings)):
            ing = ings[i]
            if ing[-1] == '%':
                b -= int(ing[:-1]) / 100
            elif ing[-1] == 'g':
                a += int(ing[:-1]) * helper[i]
            elif ing[-1] == 'C':
                a += int(ing[:-1])
        x = a / b
        if ings[0][-1] == '%':
            numerator += int(ings[0][:-1]) / 100 * x
        elif ings[0][-1] == 'g':
            numerator += int(ings[0][:-1]) * helper[0]
        elif ings[0][-1] == 'C':
            numerator += int(ings[0][:-1])
        denominator += x
    return round(numerator * 100 / denominator + 1e-9)

if __name__ == '__main__':
    lines = []
    while True:
        line = input()
        if line == '-':
            if lines:
                print(solve(lines), end='%\n')
                lines.clear()
            else:
                break
        else:
            lines.append(line)
