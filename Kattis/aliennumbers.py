# Alien Numbers

for _ in range(int(input())):
    alien_number, source_language, target_language = input().split()
    s, t, exponent, base_ten = len(source_language), len(target_language), 1, 0
    for digit in reversed(alien_number):
        base_ten += source_language.find(digit) * exponent
        exponent *= s
    ans = []
    while base_ten > 0:
        ans.append(target_language[base_ten % t])
        base_ten //= t
    print(f'Case #{_+1}:', end=' ')
    print(''.join(reversed(ans)))
    