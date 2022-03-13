# Pig Latin

vowels = {'a', 'e', 'i', 'o', 'u', 'y'}

def is_vowel(char):
    return char in vowels

def solve_for_a_word(word):
    if is_vowel(word[0]):
        return word + 'yay'
    first_vowel_index = 0
    for i in range(1, len(word)):
        if is_vowel(word[i]):
            first_vowel_index = i
            break
    return word[first_vowel_index:] + word[:first_vowel_index] + 'ay'

def solve_for_a_line(line):
    return ' '.join([solve_for_a_word(word) for word in line.split()])


if __name__ == '__main__':
    while True:
        try:
            print(solve_for_a_line(input()))
        except EOFError:
            break