# Emag Eht Htiw Em Pleh

out = """+---+---+---+---+---+---+---+---+
|...|:::|...|:::|...|:::|...|:::|
+---+---+---+---+---+---+---+---+
|:::|...|:::|...|:::|...|:::|...|
+---+---+---+---+---+---+---+---+
|...|:::|...|:::|...|:::|...|:::|
+---+---+---+---+---+---+---+---+
|:::|...|:::|...|:::|...|:::|...|
+---+---+---+---+---+---+---+---+
|...|:::|...|:::|...|:::|...|:::|
+---+---+---+---+---+---+---+---+
|:::|...|:::|...|:::|...|:::|...|
+---+---+---+---+---+---+---+---+
|...|:::|...|:::|...|:::|...|:::|
+---+---+---+---+---+---+---+---+
|:::|...|:::|...|:::|...|:::|...|
+---+---+---+---+---+---+---+---+""".split('\n')

if __name__ == "__main__":
    for i in range(len(out)):
        out[i] = list(out[i])
    whites = input()[7:].split(',')
    for w in whites:
        if w == '':
            break
        if len(w) == 2:
            i = 8 - int(w[1])
            j = ord(w[0]) - ord('a')
            out[2 * i + 1][4 * j + 2] = 'P'
        else:
            i = 8 - int(w[2])
            j = ord(w[1]) - ord('a')
            out[2 * i + 1][4 * j + 2] = w[0]
    blacks = input()[7:].split(',')
    for b in blacks:
        if b == '':
            break
        if len(b) == 2:
            i = 8 - int(b[1])
            j = ord(b[0]) - ord('a')
            out[2 * i + 1][4 * j + 2] = 'p'
        else:
            i = 8 - int(b[2])
            j = ord(b[1]) - ord('a')
            out[2 * i + 1][4 * j + 2] = b[0].lower()
    for i in range(len(out)):
        out[i] = ''.join(out[i])    
    print('\n'.join(out))