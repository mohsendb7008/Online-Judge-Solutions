# Anagram Counting

from collections import Counter

if __name__ == '__main__':
    fact = [1]
    for i in range(1, 101):
        fact.append(i * fact[i-1])
    while True:
        try:
            word = input()
        except EOFError:
            break
        ans = fact[len(word)]
        for count in Counter(word).values():
            ans //= fact[count]
        print(ans)   