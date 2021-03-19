from collections import Counter

# Seven Wonders

if __name__ == "__main__":
    s = sorted(list(Counter(input()).values()))
    sum = 0
    for item in s:
        sum += item ** 2
    if len(s) == 3: 
        sum += 7 * s[0]
    print(sum)
