# False Sense of Security

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_,.?"
morse = ".- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --.. ..-- .-.- ---. ----"

to_morse, from_morse = {}, {}

def encode(s):
    ans, numbers = "", ""
    for c in s:
        ans += to_morse[c]
        numbers += str(len(to_morse[c]))
    return ans, numbers

def decode(s, t):
    ans, ind = "", 0
    for c in t:
        l = int(c)
        ans += from_morse[s[ind : ind + l]]
        ind += l
    return ans

if __name__ == '__main__':
    for a, b in zip(alphabet, morse.split()):
        to_morse[a] = b
        from_morse[b] = a
    while True:
        try:
            line = input()
            s, t = encode(line)
            print(decode(s, t[::-1]))
        except EOFError:
            break